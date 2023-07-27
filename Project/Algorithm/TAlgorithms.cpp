#include <Algorithm/TAlgorithms.h>
#include <functional>
#define _USE_MATH_DEFINES
#include <math.h>

std::vector<SMapPoint> TAlgorithms::SGridUtility::NeighbourOffsets = {
	{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
};

std::vector<SMapPoint> TAlgorithms::SGridUtility::SideNeighbourOffsets = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

SMapPoint TAlgorithms::SGridUtility::InvalidPoint = {-1, -1};

TAlgorithms::SGridUtility::SNeighboursBlock TAlgorithms::SGridUtility::s_xNeighboursBlock = {{0, 1}, {1, 1}, {1, 0}};

template <>
double TAlgorithms::EuclideanDistance<SMapPoint>(const SMapPoint& A, const SMapPoint& B) {
	return EuclideanDistance( SMapPoint(A.x, A.y), SMapPoint(B.x, B.y));
}

bool TAlgorithms::HasSubStr(const std::string& text, const std::string& str, bool caseSensative) {
	std::function<std::string(const std::string&)> stringConverter = [](const auto& str) {return str;};
	if(!caseSensative) stringConverter = crx::ToLowerCase;
	return stringConverter(text).find( stringConverter(str) )!=std::string::npos;
}

bool TAlgorithms::HasSubStr(const std::string& text, const std::vector<std::string>& strs, bool caseSensative) {
	for(auto& str:strs) if( HasSubStr(text, str) ) return true;
	return false;
}

SMapPoint TAlgorithms::RotatePoint(const SMapPoint& point, float rad, const SMapPoint& center) {
	auto x = (float)point.x;
	auto y = (float)point.y;
	crx::RotatePoint2D(x, y, rad, (float)center.x, (float)center.y);
	return { (int)std::round(x), (int)std::round(y) };
}

float TAlgorithms::MinDistanceBetweenPoints(int sectionsByWidth, int sectionsByHeight, int sectionSize, int pointsNumber) {
	return sectionSize*std::sqrt( float(sectionsByWidth*sectionsByHeight)/float(pointsNumber) );
}

void TAlgorithms::SGridManipulator::SetArea(std::vector<std::vector<bool>>& grid, bool value, const SBox2D& area) {
	for(auto x = (int)area.Min.x; x<(int)area.Max.x; ++x) {
		for(auto y = (int)area.Min.y; y<(int)area.Max.y; ++y) {
			grid[x][y] = value;
		} // for(y)
	} // for(x)
}

void TAlgorithms::SGridManipulator::SetBorder(	std::vector<std::vector<bool>>& grid, bool value,
												const SMapPoint& borderSize, const SBox2D& area) {
	// Notes: '#' - area, '-' - free space

	// # - -
	// # - -
	// # - -
	SetArea( grid, value, SBox2D{{area.Min.x, area.Min.y}, {area.Min.x+borderSize.x, area.Max.y}} );

	// - - #
	// - - #
	// - - #
	SetArea( grid, value, SBox2D{{area.Max.x-borderSize.x, area.Min.y},{ area.Max.x, area.Max.y}} );


	// - - -
	// - - -
	// # # #
	SetArea( grid, value, SBox2D{{area.Min.x, area.Min.y}, {area.Max.x, area.Min.y+borderSize.y}} );
	
	// # # #
	// - - -
	// - - -
	SetArea( grid, value, SBox2D{{area.Min.x, area.Max.y-borderSize.y}, {area.Max.x, area.Max.y}} );
}

void TAlgorithms::SGridManipulator::SetBorder(std::vector<std::vector<bool>>& grid, bool value, const SMapPoint& borderSize) {
	auto min = SMapPoint(0, 0);
	auto max =SMapPoint( (int)grid.size(), (int)grid.front().size() );

	SetBorder( grid, value, borderSize, SBox2D{min, max} );
}

static std::vector<SMapPoint> GridFilter(	const std::vector<std::vector<bool>>& grid, 
											std::function<bool(int, int)> filter) {
	
	auto width = grid.size();
	auto height = grid.front().size();

	std::vector<SMapPoint> result;
	for(unsigned x = 0; x<width; ++x) {
		for(unsigned y = 0; y<height; ++y) {
			if( filter(x, y) ) result.emplace_back(x, y);
		} // for(y)
	} // for(x)
	return result;
}

std::vector<SMapPoint> TAlgorithms::SGridUtility::ExtractWalkable(const std::vector<std::vector<bool>>& grid) {
	auto filter = [&](int x, int y){ return grid[x][y]; };
	return GridFilter(grid, filter);
}

std::vector<SMapPoint> TAlgorithms::SGridUtility::ExtractWalkableExits(const std::vector<std::vector<bool>>& grid) {
	auto filter = [&](int x, int y){ return grid[x][y] && HasOneNeighbour({x, y}, grid); };
	return GridFilter(grid, filter);
}

std::vector<SMapPoint> TAlgorithms::SGridUtility::Neighbours(const std::vector<std::vector<bool>>& grid, const SMapPoint& at) {
	std::vector<SMapPoint> result;
	for(auto& neighbour:SideNeighbourOffsets) {
		auto cell = at +neighbour;
		if( !TAlgorithms::IsOutside(cell, grid) ) result.push_back(cell);
	}
	return result;
}

void TAlgorithms::SGridUtility::PathCorrection(std::vector<std::vector<bool>>& grid) {
	auto width = grid.size();
	auto height = grid.front().size();

	std::vector<SMapPoint> result;
	for(unsigned x = 0; x<width; ++x) {
		for(unsigned y = 0; y<height; ++y) {
			if( !grid[x][y] ) continue;
			if( IsCollapsingAllowed( SMapPoint(x, y), grid ) ) grid[x][y] = false;
		} // for(y)
	} // for(x)
}

void TAlgorithms::SGridUtility::PathMerging(std::vector<std::vector<bool>>& grid,
											const std::vector<std::vector<SMapPoint>>& paths, bool autoCorrection) {
	
	std::set<SMapPoint> mergedPaths;
	for(auto& path:paths) for(auto& cell:path) mergedPaths.emplace(cell);

	for(auto& cell:mergedPaths) grid[cell.x][cell.y] = true;

	if(autoCorrection) PathCorrection(grid);
}

bool TAlgorithms::SGridUtility::HasOneNeighbour(const SMapPoint& point, const std::vector<std::vector<bool>>& grid) {
	auto neighbourCount = 0;

	for(auto& offset:SideNeighbourOffsets) {
		auto cell = point+offset;
		if( TAlgorithms::IsOutside(cell, grid) ) continue;
		if( grid[cell.x][cell.y] ) ++neighbourCount;
	}
	return neighbourCount==1;
}

bool TAlgorithms::SGridUtility::IsBlocked(const SMapPoint& point, const std::vector<std::vector<bool>>& grid) {
	return !TAlgorithms::IsOutside(point, grid) && grid[point.x][point.y];
}

bool TAlgorithms::SGridUtility::HasNeighboursBlock(const SMapPoint& point, const std::vector<std::vector<bool>>& grid, float& rad) {
	for(rad = 0.f; rad<(float)M_PI*2; rad += (float)M_PI/2) {
		if( IsBlocked( point+TAlgorithms::RotatePoint(s_xNeighboursBlock.Left, rad), grid ) &&
			IsBlocked( point+TAlgorithms::RotatePoint(s_xNeighboursBlock.Center, rad), grid ) &&
			IsBlocked( point+TAlgorithms::RotatePoint(s_xNeighboursBlock.Right, rad), grid ) ) {
			return true;
		}
	} // for
	return false;
}

bool TAlgorithms::SGridUtility::IsPatternEquals(const SMapPoint& point, const std::vector<std::vector<bool>>& grid, 
												const std::vector<std::pair<SMapPoint, int>>& pattern) {

	for(auto& [offset, state]:pattern) {
		auto cell = point+offset;
		auto cellState = TAlgorithms::IsOutside(cell, grid)?false:grid[cell.x][cell.y];
		if(cellState!=bool(state)) return false;
	}
	return true;
}

bool TAlgorithms::SGridUtility::IsCollapsingAllowed(const SMapPoint& point, const std::vector<std::vector<bool>>& grid) {
	float rad = 0.f;
	if( !HasNeighboursBlock(point, grid, rad) ) return false;

	// lr  L  C
	//  r  x  R
	//  c  l rl
	auto rl = TAlgorithms::RotatePoint( {s_xNeighboursBlock.Right.x, -s_xNeighboursBlock.Left.y}, rad );
	auto l = TAlgorithms::RotatePoint( s_xNeighboursBlock.Left, float(rad+M_PI) );
	auto c = TAlgorithms::RotatePoint( s_xNeighboursBlock.Center, float(rad+M_PI) );
	auto r = TAlgorithms::RotatePoint( s_xNeighboursBlock.Right, float(rad+M_PI) );
	auto lr = TAlgorithms::RotatePoint( {-s_xNeighboursBlock.Right.x, s_xNeighboursBlock.Left.y}, rad );

	std::vector<std::vector<std::pair<SMapPoint, int>>> incompatiblePatterns = {
		{{lr, 0}, {r, 1}, {c, 0}, {l, 0}, {rl, 0}},
		{{lr, 0}, {r, 0}, {c, 0}, {l, 1}, {rl, 0}},
		{{lr, 0}, {r, 1}, {c, 0}, {l, 0}, {rl, 1}},
		{{lr, 1}, {r, 0}, {c, 0}, {l, 1}, {rl, 0}},
		{{lr, 0}, {r, 1}, {c, 0}, {l, 1}, {rl, 1}},
		{{lr, 1}, {r, 1}, {c, 0}, {l, 1}, {rl, 0}},

		{{lr, 0}, {r, 1}, {c, 1}, {l, 0}, {rl, 0}},
		{{lr, 0}, {r, 0}, {c, 1}, {l, 1}, {rl, 0}},
		{{lr, 0}, {r, 1}, {c, 1}, {l, 0}, {rl, 1}},
		{{lr, 1}, {r, 0}, {c, 1}, {l, 1}, {rl, 0}},

		{{lr, 0}, {r, 1}, {c, 1}, {l, 1}, {rl, 0}},
		{{lr, 0}, {r, 1}, {c, 0}, {l, 1}, {rl, 0}},
	};

	for(auto& pattern:incompatiblePatterns) if( IsPatternEquals(point, grid, pattern) ) return false;
	return true;
}
