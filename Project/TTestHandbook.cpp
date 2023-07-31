#include <CRX/Base/TXTest.h>
#include <CRX/Reflection/magic_enum.h>

#include <WorldComponents/THandbook.h>

struct TTestHandbook : crx::TDebug::TXTest {
	AUTOTEST_BODY(TTestHandbook) {
		//std::shared_ptr<THandbook>;
		Handbook()->Load();
		for(int i = 0; i<=NEntityType::Mazanka; i++) {
			auto type = (NEntityType)i;
			auto name = magic_enum::enum_name(type).data();

			auto villageWariorProto = std::make_shared<TUnitPrototype>();
			villageWariorProto->SetPrototype(type);
			Handbook()->UnitPrototypes[name] = villageWariorProto;
			Handbook()->Save();
		}
		//Handbook()->Load();
		auto villageWariorProto = std::make_shared<TUnitPrototype>();
		villageWariorProto->SetPrototype(NEntityType::VillageWarior);
		Handbook()->UnitPrototypes["VillageWarior"] = villageWariorProto;












		Handbook()->Save();
		auto& data = Handbook()->UnitPrototypes;
		Handbook()->Save();

	}
};
