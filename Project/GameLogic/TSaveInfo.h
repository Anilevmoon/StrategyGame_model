#ifndef TSAVE_INFO_H
#define TSAVE_INFO_H

#include <WorldComponents/TObject.h>

class TSaveInfo : public TObject{
	public:
	TSaveInfo()=default;
	~TSaveInfo()=default;

	protected:
	char* m_pData = nullptr;
	std::string m_sDate; 
};

#endif // TSAVE_INFO_H


