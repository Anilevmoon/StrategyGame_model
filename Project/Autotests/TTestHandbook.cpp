#include <CRX/Base/TXTest.h>
#include <CRX/Reflection/magic_enum.h>

#include <WorldComponents/THandbook.h>

struct TTestHandbook : crx::TDebug::TXTest {
	AUTOTEST_BODY(TTestHandbook) {

		//Handbook()->Load();
		THandbook* handbook = Handbook();
		handbook->Load();
		std::shared_ptr<TUnit> unit = std::make_shared<TUnit>();

		{
			unit->SetEntityPrototype(handbook->GetUnitPrototypeByName("Kozak"));
			Assert(unit->m_pPrototype->m_xType==NEntityType::Kozak, " Created from Handbook Kozak");
		}

		{
			unit->SetEntityPrototype(handbook->GetUnitPrototypeByName("ForestMavka"));
			Assert(unit->m_pPrototype->m_xType==NEntityType::ForestMavka, " Created from Handbook ForestMavka");
		}
		
	//	for(int i = 0; i<=NEntityType::Mazanka; i++) {
	//		auto type = (NEntityType)i;
	//		auto name = magic_enum::enum_name(type).data();

	//		auto villageWariorProto = std::make_shared<TUnitPrototype>();
	//		villageWariorProto->SetPrototype(type);
	//		Handbook()->UnitPrototypes[name] = villageWariorProto;
	//		Handbook()->Save();
	//	}

	//	//Handbook()->Load();
	//	for(int i = 0; i<=NBuffType::ShittyArmor; i++) {
	//		auto type = (NBuffType)i;
	//		auto name = magic_enum::enum_name(type).data();

	//		auto BuffProto = std::make_shared<TBuffPrototype>(type);
	//		Handbook()->BuffPrototypes[name] = BuffProto;
	//		Handbook()->Save();
	//	}

	////	Handbook()->Load();
	//	for(int i = 0; i<=NOwner::Player2; i++) {
	//		auto type = (NOwner)i;
	//		auto name = magic_enum::enum_name(type).data();

	//		auto PlayerProto = std::make_shared<TPlayerPrototype>(type);
	//		Handbook()->PlayerPrototypes[name] = PlayerProto;
	//		Handbook()->Save();
	//	}

	//	{
	//		//Handbook()->Load();
	//		auto WorldProto = std::make_shared<TWorldPrototype>();
	//		auto name = "World";
	//		Handbook()->WorldPrototypes[name] = WorldProto;
	//		Handbook()->Save();
	//	}

	//	for(int i = 0; i<=NMapType::NoUnits; i++) {
	//		auto type = (NMapType)i;
	//		auto name = magic_enum::enum_name(type).data();

	//		auto PlayerProto = std::make_shared<TMapPrototype>(type);
	//		Handbook()->MapPrototypes[name] = PlayerProto;
	//		Handbook()->Save();
	//	}

	//	Handbook()->Save();
	//	auto& data = Handbook()->UnitPrototypes;
	//	Handbook()->Save();

	}
};
