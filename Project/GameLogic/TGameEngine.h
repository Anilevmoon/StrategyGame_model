#ifndef TGAME_ENGINE_H
#define TGAME_ENGINE_H

#include <WorldComponents/TObject.h>
#include <map>

class TGameSession;

class TGameEngine : public TObject {
	public:
	TGameEngine()=default;
	~TGameEngine()=default;

	public:
	void AddGameSession(std::string name, std::shared_ptr<TGameSession> session);
	void ChangeGameSession(std::string nameNewSession);
	void SetCurrentSession(std::string sessionName);

	public:
	std::shared_ptr<TGameSession> p_CurrentSession;
	std::map<std::string, std::shared_ptr<TGameSession>> m_pSesions;

};

#endif //TGAME_ENGINE_H

