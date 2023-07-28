#ifndef TBUILDINGS_PROTOTYPE_H
#define TBUILDINGS_PROTOTYPE_H

#include <Prototypes/TBuffPrototype.h>
#include <Enums/NEntityType.h>
class TBuildingsPrototype :public TObject {
	public:
	TBuildingsPrototype()=default;
	void SetBuildingsPrototype(NEntityType type);
	
	public:
	float m_fHealth = 0.f;

	public:
	NEntityType m_xType;
	std::vector<std::shared_ptr<TBuffPrototype>> m_vBuffPrototypesContainer;
};

#endif // TBUILDINGS_PROTOTYPE_H