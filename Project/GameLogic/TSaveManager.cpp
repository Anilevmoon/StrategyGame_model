#include <GameLogic/TSaveManager.h>
#include <GameLogic/TSaveInfo.h>

void TSaveManager::AddDate(std::shared_ptr<TSaveInfo> InputData) {
	v_SavedInfoContainer.push_back(InputData);
}

//void TSaveManager::RemoveDate(std::shared_ptr<TSaveInfo> Date) {
//	auto filter = [Date](auto a) { return a->Date() == Date->Date(); };
//	auto it = std::remove_if( v_SavedInfoContainer.begin(), v_SavedInfoContainer.end(), filter );
//	v_SavedInfoContainer.erase( it, v_SavedInfoContainer.end() );
//}
