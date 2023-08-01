#ifndef TMAP_PROTOTYPE_H
#define TMAP_PROTOTYPE_H
#include <Enums/NMapType.h>
#include <Prototypes/TUnitPrototype.h>
#include <Prototypes/TBuildingsPrototype.h>


static int s_iWidth = 20;
static int s_iLenght = 30;
static int s_iHeight = 3;
static int s_iLayer = 0;

class TMapPrototype : public TObject {
	public:
	TMapPrototype(NMapType type = NMapType::Flat);
	virtual ~TMapPrototype()=default;
	DECL_REFLECTION_TABLE();

	public:
	int m_iWidth =  s_iWidth;
	int m_iLenght = s_iLenght;
	int m_iHeight = s_iHeight;
	int m_iLayer =  s_iLayer;

	public:
	NMapType m_xMapType;
	public:
	std::vector<std::shared_ptr<TUnitPrototype>> m_vUnitPrototypesOnMapContainer;	//Same quations;
	std::vector<std::shared_ptr<TBuildingsPrototype>> m_vBuildingsPrototypesOnMapContainer;



};

#endif //TMAP_PROTOTYPE_H