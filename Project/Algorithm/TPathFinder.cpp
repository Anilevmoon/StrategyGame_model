//#include <TPathFinder.h>
#include <Algorithm/TPathFinder.h>
#include <cmath>
#include <map>
#include <queue>
#include <tuple>

TPathFinder::TPathFinder() {
	MoveCostFunction = DefaultMoveCostFunction();
	NeighbourFinderFunction = DefaultNeighbourFinderFuncion();
	HeuristicFunction = DefaultHeuristicFunction();
}

std::vector<SMapPoint> TPathFinder::FindPathTo(	const std::vector<std::vector<int>>& grid,
													const SMapPoint& start, const SMapPoint& goal) {
	
	std::vector<SMapPoint> path;

	std::map<SMapPoint, SMapPoint> reversePath;
	std::map<SMapPoint, int> pathCost;

	using TCellCost = std::pair<int, SMapPoint>;
	std::priority_queue<TCellCost, std::vector<TCellCost>, std::greater<TCellCost>> frontier;

	frontier.emplace(0, start);

	reversePath[start] = start;
 	pathCost[start] = 0;

	while( !frontier.empty() ) {
		auto current = frontier.top().second;
		frontier.pop();

		if(current==goal) break;

		auto neighbours = NeighbourFinderFunction(grid, current);			//NO NEIGHBORS!!!!!!!
		for(auto& cell:neighbours) {
			auto newCost = MoveCostFunction(grid, cell);
			if(newCost==NoMove) continue;

			newCost += pathCost[current];
			if( !pathCost.count(cell) || newCost<pathCost[cell] ) {
				reversePath[cell] = current;
				pathCost[cell] = newCost;

				frontier.emplace( newCost+(int)HeuristicFunction(cell, goal), cell );
			}
		} // for(cell)
	} // while(frontier)

	path.push_back(goal);
	for(auto current = goal; current!=start;) {
		auto it = reversePath.find(current);
		if( it==reversePath.end() ) return {};

		current = it->second;
		path.push_back(current);
	}

	return std::vector<SMapPoint>( path.rbegin(), path.rend() );
}

TPathFinder::TMoveCostFunction TPathFinder::DefaultMoveCostFunction() {
	return [](const std::vector<std::vector<int>>& grid, const SMapPoint& at) {
		return grid[at.x][at.y];
	};
}

TPathFinder::TNeighbourFinderFunction TPathFinder::DefaultNeighbourFinderFuncion() {
	return [](const std::vector<std::vector<int>>& grid, const SMapPoint& at) {
		std::vector<SMapPoint> result;
		for(auto& offset:TAlgorithms::SGridUtility::NeighbourOffsets) {
			auto cell = at+offset;
			if( !TAlgorithms::IsOutside(cell, grid) ) result.push_back(cell);
		} // for(offset)
		return result;
	};
}

TPathFinder::THeuristicFunction TPathFinder::DefaultHeuristicFunction() {
	return [](const SMapPoint& A, const SMapPoint& B) {
		return float( std::abs(A.x-B.x)+std::abs(A.y-B.y) );
	};
}
