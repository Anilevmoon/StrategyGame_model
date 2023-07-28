#include <CRX/Base/TDebug.h>
#include <CRX/Base/TXTest.h>

#include <EntityPart/TBuildings.h>
#include <WorldComponents/TStartEntityCreator.h>
#include <Enums/NEntityType.h>

static bool IsEqual(SMapPoint cache, SMapPoint cache2) {
	if( cache == cache2 ) return true;
	return false;
}


struct TTestBuild :crx::TDebug::TXTest {
	
	SMapPoint coordinate{1,1,1,1};

	AUTOTEST_BODY(TTestBuild) {
		
		TBuildings build = TBuildings();
		build.SetEntityPrototype(NEntityType::Coliba);

		TBuildings build2 = TBuildings();
		build2.SetEntityPrototype(NEntityType::CossacksHouse);

		TBuildings bil = TBuildings();

		Assert(build.m_pPrototype->m_fHealth==800, "Create FIrstBuild");
		Assert(build2.m_pPrototype->m_fHealth==1000, "Create SecondBuild");

		build.SetCoordinates(coordinate);
		Assert(IsEqual(coordinate, build.m_xLocation), "Set Coordinates");

		build.DestroyEntity();
		Assert(build.m_pPrototype->m_fHealth==0, "Destroy First Building ");
		build2.DestroyEntity();
		Assert(build2.m_pPrototype->m_fHealth==0, "Destroy Second Building");

	}
};
