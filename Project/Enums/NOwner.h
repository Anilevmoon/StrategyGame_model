#ifndef NOWNER_H
#define NOWNER_H

namespace NNOwner {
	enum NOwner {
		PC,
		Player1,
		Player2
	};
}

using NOwner = NNOwner::NOwner;

#endif //NOWNER_H