#ifndef NNMAGIC_TYPE_H
#define NNMAGIC_TYPE_H

namespace NNBuffType {
	enum NBuffType {
		Hill,
		Regeneration,
		DiamondArmor,
		PowerAttack,

		Poison,
		Weakness,
		ShittyArmor
	};

}
using NBuffType = NNBuffType::NBuffType;

#endif //NNMAGIC_TYPE_H