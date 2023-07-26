#include <CRX/Base/TDebug.h>
#include <CRX/Base/TXTest.h>

#include <EntityPart/TBuildings.h>
#include <WorldWideComp/TStartEntityCreator.h>
#include <Enums/NEntityType.h>

bool IsEqual(const std::vector<SMapPoint> cache, const std::vector<std::shared_ptr<SMapPoint>> cache2) {
	for(int i = 0; i<cache.size(); ++i) {
		if(cache[i].x==cache2[i]->x&&cache[i].y==cache2[i]->y&&\
		   cache[i].z==cache2[i]->z&&cache[i].w==cache2[i]->w) return true;
	}
	return false;
}


struct TTestBuild :crx::TDebug::TXTest {

	SMapPoint cache1 ={1, 2, 3, 4};
	SMapPoint cache2 ={2, 2, 3, 4};
	SMapPoint cache3 ={3, 2, 3, 4};

	std::vector<SMapPoint> vec{{1, 2, 3, 4}, {2, 2, 3, 4}, {3, 2, 3, 4} };

	AUTOTEST_BODY(TTestBuild) {

		//TBuildings build = TBuildings();
		//build.SetEntityPrototype(NEntityType::Coliba);

		//TBuildings build2 = TBuildings();
		//build2.SetEntityPrototype(NEntityType::CossacksHouse);

		//TBuildings bil = TBuildings();

		//Assert(build.m_pPrototype->m_fHealth==800, "FIrstBuild");
		//Assert(build2.m_pPrototype->m_fHealth==1000, "SecondBuild");

		//build.SetCoordinates(vec);
		//Assert(IsEqual(vec, build.m_pPrototype->m_vBuildPoints), "Coordinates");

		//build.DestroyEntity();
		//Assert(build2.m_pPrototype->m_fHealth==1000, "SecondBuild");
		//build2.DestroyEntity();
		//Assert(build.m_pPrototype->m_fHealth==0, "DestroyFirst");
		//build2.DestroyEntity();
		//Assert(build2.m_pPrototype->m_fHealth==0, "DestroySecond");

		//{
		//	TBuildings build = TBuildings();
		//	TBuildings build2 = TBuildings();
		//	TStartEntityCreator fabric{};
		//}

	}
};
