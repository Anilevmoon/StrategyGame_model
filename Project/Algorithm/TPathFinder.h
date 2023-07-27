#ifndef ALGORITHM_TPATHFINDER_H_
#define ALGORITHM_TPATHFINDER_H_

#include <functional>
#include <vector>
#include <MapParts/SMapPoint.h>

#include <Algorithm/TAlgorithms.h>


class TPathFinder {
	public:
	TPathFinder();

	public:
	std::vector<SMapPoint> FindPathTo(const std::vector<std::vector<int>>& grid, const SMapPoint& start, const SMapPoint& goal);

	public:
	using TMoveCostFunction = std::function<int(const std::vector<std::vector<int>>&, const SMapPoint&)>;
	using TNeighbourFinderFunction = std::function<std::vector<SMapPoint>(const std::vector<std::vector<int>>&, const SMapPoint&)>;
	using THeuristicFunction = std::function<float(const SMapPoint& A, const SMapPoint& B)>;

	public:
	TMoveCostFunction DefaultMoveCostFunction();
	TNeighbourFinderFunction DefaultNeighbourFinderFuncion();
	THeuristicFunction DefaultHeuristicFunction();

	protected:
	template <typename DstFunction, typename SrcFunction>
	void SetFunction(DstFunction& dst, SrcFunction src) { if(src) dst = src; }

	public:
	TMoveCostFunction MoveCostFunction = nullptr;
	TNeighbourFinderFunction NeighbourFinderFunction = nullptr;
	THeuristicFunction HeuristicFunction = nullptr;

	public:
	static inline int NoMove = 0;
	static inline int MoveMinimal = 1;
};

#endif /* ALGORITHM_TPATHFINDER_H_ */