#ifndef ALGORITHM_TALGORITHMS_H_
#define ALGORITHM_TALGORITHMS_H_

#include <utility>
#include <set>
#include <vector>
#include <string>
#include <MapParts/SMapPoint.h>
#include <Algorithm/TLightStaticRandom.h>
#include <Algorithm/SBox2D.h>
#include <CRX/Base/TMiscUtils.h>
//#include <CRX/Base/TPoint.h>

class TAlgorithms {
	public:
	struct SGridUtility;
	struct SGridManipulator;

	public:
	template <typename TwoDimensionVector>
	static double EuclideanDistance(const TwoDimensionVector& A, const TwoDimensionVector& B) {
		auto diffX = A[0]-B[0];
		auto diffY = A[1]-B[1];

		return diffX*diffX+diffY*diffY;
	}

	template <class TwoDimensionVector, class TwoDimensionContainer>
	static bool IsOutside(const TwoDimensionVector& vector, const TwoDimensionContainer& container) {
		auto x = (int)vector[0];
		auto y = (int)vector[1];
		return x<0 || x>=(int)container.size() || y<0 || y>=(int)container.front().size();
	}

	// return nearest point and euclidean distance to
	template <typename TwoDimensionVector, class ContainerTwoDimensionVector>
	static std::pair<std::size_t, TwoDimensionVector> FindNearestPoint(const TwoDimensionVector& at, const ContainerTwoDimensionVector& between) {
		auto distanceAndPoint = std::make_pair( std::size_t(-1), TwoDimensionVector(-1, -1) );

		for(auto& point:between) {
			auto currDistance = (std::size_t)EuclideanDistance(at, point);
			if(distanceAndPoint.first>currDistance) distanceAndPoint = {currDistance, point};
		}
		return distanceAndPoint;
	}

	template <class ContainerType>
	static uint32_t SelectRandomPosition(const ContainerType& container) {
		auto size = std::distance( container.begin(), container.end() );
		return StaticRandom.RandRange( 0, uint32_t(size-1) );
	}

	//  only for non empty containers, check size manualy
	template <class ContainerType>
	static decltype(auto) SelectRandomItem(ContainerType& container) {
		return *std::next(container.begin(), SelectRandomPosition(container) );
	}
	
	//  only for non empty containers, check size manualy

	// select random items with
	template <class ContainerType>
	static ContainerType SelectRandomItems(const ContainerType& container, uint32_t minItemsCount, uint32_t maxItemsCount) {
		if( container.empty() ) return container;

		auto selectedItems = container;
		StaticRandom.RandomShuffle( selectedItems.begin(), selectedItems.end() );

		auto newSize = StaticRandom.RandRange(minItemsCount, maxItemsCount);
		selectedItems.resize(newSize);

		return selectedItems;
	}

	template <class ContainerType, class ContainerDataType>
	static bool IsContainsData(const ContainerType& container, const ContainerDataType& data) {
		for(auto& item:data) if( !crx::IsContain(container, item) ) return false;
		return true;
	}

	template <class ContainerType, typename ItemType>
	static void RemoveFromContainer(ContainerType& container, const ItemType& item) {
		 container.erase( std::remove(container.begin(), container.end(), item), container.end() );
	}

	// return single container from container array without dublicates
	template <template <class> class ArrayType, class ContainerType>
	static ContainerType ContainerMerge(const ArrayType<ContainerType>& containers) {
		std::set<typename ContainerType::value_type> unique;
		for(auto& container:containers) unique.insert( container.begin(), container.end() );

		return ContainerType( unique.begin(), unique.end() );
	}
	
	static bool HasSubStr(const std::string& text, const std::string& str, bool caseSensative=false);
	static bool HasSubStr(const std::string& text, const std::vector<std::string>& strs, bool caseSensative=false);

	static SMapPoint RotatePoint(const SMapPoint& point, float rad, const SMapPoint& center = SMapPoint());
	
	// MS = sqrt((a1^2+a2^2+...+an^2)/n)
	template <typename ArithmeticType>
	static double MeanSquare(const std::vector<ArithmeticType>& numbers) {
		auto sum = 0.0;
		for(auto number:numbers) sum += number*number;
		return std::sqrt( sum/numbers.size() );
	}
	
	// Calculate distance for grid with width x height (sections) and section size
	// You can select field and dividy by sections for specify dencity level
	static float MinDistanceBetweenPoints(int sectionsByWidth, int sectionsByHeight, int sectionSize, int pointsNumber);
	
	public:
	static inline TLightStaticRandom StaticRandom;
};

struct TAlgorithms::SGridUtility {
	public:
	// create grid with cpecify type and filler
	template <typename T = bool>
	static std::vector<std::vector<T>> CreateGrid(unsigned width, unsigned height, const T& filler = T{}) {
		return { width, std::vector<T>(height, filler) };
	}

	// reset grid items to default filler value
	template <typename T = bool>
	static void ResetGrid(std::vector<std::vector<T>>& grid, const T& filler = T{}) {
		for(auto& vector:grid) vector.assign(vector.size(), filler);
	}

	public:
	static std::vector<SMapPoint> ExtractWalkable(const std::vector<std::vector<bool>>& grid);
	static std::vector<SMapPoint> ExtractWalkableExits(const std::vector<std::vector<bool>>& grid);

	public:
	static std::vector<SMapPoint> Neighbours(const std::vector<std::vector<bool>>& grid, const SMapPoint& at);

	public:
	static void PathCorrection(std::vector<std::vector<bool>>& walkable);

	// set true state for path cells at grid
	static void PathMerging(std::vector<std::vector<bool>>& grid, const std::vector<std::vector<SMapPoint>>& paths, bool auto_correction = true);

	protected:
	static bool HasOneNeighbour(const SMapPoint& point, const std::vector<std::vector<bool>>& grid);
	static bool IsBlocked(const SMapPoint& point, const std::vector<std::vector<bool>>& grid);

	protected:
	static bool HasNeighboursBlock(const SMapPoint& point, const std::vector<std::vector<bool>>& grid, float& rad);
	static bool IsPatternEquals(const SMapPoint& point, const std::vector<std::vector<bool>>& grid, const std::vector<std::pair<SMapPoint, int>>& pattern);
	static bool IsCollapsingAllowed(const SMapPoint& point, const std::vector<std::vector<bool>>& grid);
	
	protected:
	struct SNeighboursBlock {
		SMapPoint Left;
		SMapPoint Center;
		SMapPoint Right;
	};

	public:
	static std::vector<SMapPoint> NeighbourOffsets;
	static std::vector<SMapPoint> SideNeighbourOffsets;

	public:
	static SMapPoint InvalidPoint;

	protected:
	static SNeighboursBlock s_xNeighboursBlock;
};

struct TAlgorithms::SGridManipulator {
	public:
	static void SetArea(std::vector<std::vector<bool>>& grid, bool value, const SBox2D& area);

	public:
	static void SetBorder(std::vector<std::vector<bool>>& grid, bool value, const SMapPoint& border_size, const SBox2D& area);
	static void SetBorder(std::vector<std::vector<bool>>& grid, bool value, const SMapPoint& border_size);
};

template <>
double TAlgorithms::EuclideanDistance<SMapPoint>(const SMapPoint& A, const SMapPoint& B);

#endif /* ALGORITHM_TALGORITHMS_H_ */