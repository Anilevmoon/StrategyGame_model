#ifndef TSAVE_MANAGER_H
#define TSAVE_MANAGER_H

#include <WorldComponents/TObject.h>

class TSaveInfo;

class TSaveManager : public TObject {
	public:
	TSaveManager()=default;
	~TSaveManager()=default;

	public:
	void AddDate(std::shared_ptr<TSaveInfo> InputData);
	void RemoveDate(std::shared_ptr<TSaveInfo> Date);

	public:
	std::vector<std::shared_ptr<TSaveInfo>> v_SavedInfoContainer;
};

#endif // TSAVE_MANAGER_H
	
