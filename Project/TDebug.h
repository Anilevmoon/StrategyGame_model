#ifndef CRX_BASE_DEBUGGH_H_
#define CRX_BASE_DEBUGGH_H_

#include <sstream>
#include <string>
#include <errno.h>
#include <string.h>


namespace crx {

namespace TDebug {
    bool IsConsoleOut();
    void ConsoleOut(bool);
    const std::string& LogFileName();
    void LogFileName(const std::string&);

    void Prefix(const std::string& );
    std::string Timestamp(bool withDate = false);

    void Log(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes, const std::string& logFile = LogFileName());
    void NetLog(const std::string& connection_name, const std::string& mes);
    void Error(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes);
    void VCallError(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes);

    void PrintRaw(const std::string& mes);

    void PrintThreadPID(bool bb);

    bool IsPrintSQLQuery();
    void PrintSQLQuery(bool b);

    extern bool UseLog;// это для UE Commandlet

};


#ifdef _LOG
#undef _LOG
#undef _NETLOG
#undef _ERROR
#undef _VCALL_ERROR
#undef _ERNO_ERROR
#endif

#define _LOG(xx) { if(crx::TDebug::UseLog) {std::ostringstream ___str; ___str<<xx; crx::TDebug::Log(__FILE__, __LINE__, __func__, ___str.str());} }
#define _ILOG(xx, yy) { if(crx::TDebug::UseLog) {std::ostringstream ___str; ___str<<xx; std::ostringstream ___logfilestr; ___logfilestr<<yy; crx::TDebug::Log(__FILE__, __LINE__, __func__, ___str.str(), ___logfilestr.str());} }
#define _NETLOG(tt, xx) { if(crx::TDebug::UseLog) {std::ostringstream __str; __str<<xx; crx::TDebug::NetLog(tt, __str.str()); } }
#define _ERROR(xx) { std::ostringstream ___str; ___str<<xx; crx::TDebug::Error(__FILE__,  __LINE__, __func__, ___str.str()); }
#define _VCALL_ERROR(xx)  { std::ostringstream ___str; ___str<<xx; crx::TDebug::VCallError(__FILE__,  __LINE__, __func__, ___str.str()); }
#define _ERNO_ERROR(xx) { std::ostringstream ___str; ___str<<xx<<"  Errno: "<<strerror(errno); crx::TDebug::Error(__FILE__,  __LINE__, __func__, ___str.str()); }




}

#endif
