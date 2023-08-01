#include <GameLogic/TGameEngine.h>
#include <GameLogic/TGameSession.h>

void TGameEngine::AddGameSession(std::string name, std::shared_ptr<TGameSession> session) {	m_pSesions[name] = session; }

void TGameEngine::ChangeGameSession(std::string nameNewSession) { p_CurrentSession = m_pSesions[nameNewSession]; }
void TGameEngine::SetCurrentSession(std::string sessionName) { p_CurrentSession = m_pSesions[sessionName]; }
