#include "TMapPrototype.h"
#include <CRX/Reflection/TReflectionImplDefs.h>

BEGIN_REFLECTION_TABLE(TMapPrototype, TObject)
ADD_PROPERTY(Width, m_iWidth);
ADD_PROPERTY(Lenght, m_iLenght);
ADD_PROPERTY(Height, m_iHeight);
ADD_PROPERTY(Layer, m_iLayer );
ADD_PROPERTY(UnitsOnMap, m_vUnitPrototypesOnMapContainer);
ADD_PROPERTY(BuildingsOnMap, m_vBuildingsPrototypesOnMapContainer);

END_REFLECTION_TABLE();
TMapPrototype::TMapPrototype(NMapType type) {
	m_xMapType = type;
	switch(m_xMapType)
	{

		case NMapType::Flat :
		m_iWidth =  s_iWidth;
		m_iLenght = s_iLenght;
		m_iHeight = s_iHeight;
		m_iLayer =  s_iLayer;/*
		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>());*/
		
		break;

		case NMapType::FiveOnFive:
		m_iWidth =  s_iWidth;
		m_iLenght = s_iLenght;
		m_iHeight = s_iHeight;
		m_iLayer =  s_iLayer;

		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>()); // here some quations
		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>());
		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>());
		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>());
		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>());

		//m_vBuildingsPrototypesOnMapContainer.push_back(std::make_shared<TBuildingsPrototype>());
		//m_vBuildingsPrototypesOnMapContainer.push_back(std::make_shared<TBuildingsPrototype>());
		//m_vBuildingsPrototypesOnMapContainer.push_back(std::make_shared<TBuildingsPrototype>());
		break;

		case NMapType::TenOnTen:
		m_iWidth =  s_iWidth;
		m_iLenght = s_iLenght;
		m_iHeight = s_iHeight;
		m_iLayer =  s_iLayer;/*
		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>());
		m_vUnitPrototypesOnMapContainer.push_back(std::make_shared<TUnitPrototype>());*/
		break;

		case NMapType::NoUnits:
		m_iWidth =  s_iWidth;
		m_iLenght = s_iLenght;
		m_iHeight = s_iHeight;
		m_iLayer =  s_iLayer;
		break;


		default:
		break;
	}
}
