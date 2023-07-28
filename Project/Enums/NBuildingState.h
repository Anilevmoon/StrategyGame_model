#ifndef NBUILDING_STATE_H
#define NBUILDING_STATE_H

namespace NNBuildingState {
	enum NBuildingState {
		Full,
		Half,
		Destroyed
	};
}

using NBuildingState = NNBuildingState::NBuildingState;

#endif // !NBUILDING_STATE-H

