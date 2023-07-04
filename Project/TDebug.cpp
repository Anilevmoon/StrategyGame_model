#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include "TDebug.h"

namespace crx {

namespace TDebug {

static bool s_bConsoleOut = true;

#ifdef _MSC_VER
//static std::string s_sLogFileName("c:/log.txt");
static std::string s_sLogFileName("c:/Home/Logs/log.txt");
static const std::string s_sLogDir("c:/Home/Logs/");
#else
static std::string s_sLogFileName("log.txt");
static const std::string s_sLogDir("./");
#endif
static bool s_bAppStart = false;
static std::string s_sPrefix = "";
static bool s_bPrintThreadPID = true;
static bool s_bPrintSQLQuery = true;
static bool s_bPrintCurrentTime = true;

bool UseLog = true;


bool IsPrintSQLQuery() { return s_bPrintSQLQuery; }
void PrintSQLQuery(bool b) { s_bPrintSQLQuery = b; }

bool IsConsoleOut() { return s_bConsoleOut; }
void ConsoleOut(bool b) { s_bConsoleOut = b; }

const std::string& LogFileName() { return s_sLogFileName; }
void LogFileName(const std::string& s) { s_sLogFileName = s; }

void Prefix(const std::string& s) { s_sPrefix = s; }
void PrintThreadPID(bool bb) { s_bPrintThreadPID = bb; }

static void check_app_start() {
    if(!s_bAppStart) return;
    s_bAppStart = false;
    std::ofstream f1( s_sLogFileName.c_str() );
}

std::string Timestamp(bool withDate) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    if(withDate) {
        strftime(buffer,80,"%m.%d %H:%M:%S",timeinfo);
    } else {
        strftime(buffer,80,"%H:%M:%S",timeinfo);
    }
    return std::string(buffer);
}

static std::string current_time() {
    return Timestamp(false);
}

static void out_string(const std::string& out, const std::string& logFile = LogFileName()) {
    std::ofstream ff( logFile.c_str(),  std::ios::out | std::ios::app);
    ff<<out<<std::endl;
    ff.close();
    if(s_bConsoleOut) std::cout<<out<<std::endl;
}


void PrintRaw(const std::string &mes) { out_string(mes); }

static std::string print_string(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes, const std::string& del, const std::string &logFile=LogFileName()) {
    check_app_start();
    std::string str;
    str = del;
    if( s_sPrefix.size() ) str += std::string(" -|- ") + s_sPrefix + std::string(" -|- ");
    str += module_name + std::string(":")+std::to_string(lineNumber);

    if( s_bPrintThreadPID ) {
        auto myid = std::this_thread::get_id();
        std::stringstream ss;
        ss << myid;
        std::string aa = ss.str();
        str += std::string(" (") + std::string(aa) + std::string(")");
    }

    if( s_bPrintCurrentTime ) {
        str += std::string(" (")+current_time()+std::string(") ");
    }

    str += std::string(": * ") + mes + std::string(" * ");

    auto logFilePath = logFile;
    if( logFile != s_sLogFileName ) {
        logFilePath = s_sLogDir + logFile + ".txt";
        out_string(str, s_sLogFileName);
    }

    out_string(str, logFilePath);

    return str;
}


void Log(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes, const std::string& logFile ) {
    print_string( module_name, lineNumber, functonName, mes, " ////// ", logFile);
}

void NetLog(const std::string& connection_name, const std::string& mes) {
    auto consoleOut = IsConsoleOut();
    ConsoleOut(false);

    auto prevPath = LogFileName();
    LogFileName(s_sLogDir+connection_name+".txt");

    PrintRaw(mes);

    LogFileName(prevPath);
    ConsoleOut(consoleOut);
}


static void print_error(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes, const std::string& del) {
    std::string str = print_string(module_name, lineNumber, functonName, mes, del);
    throw std::string(str);
}

void Error(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes) {
    print_error(module_name, lineNumber, functonName, mes, " --!!-- ");
}

void VCallError(const std::string& module_name, int lineNumber, const std::string& functonName, const std::string& mes) {
    std::string str = std::string("Called pure virtual method ") + mes;
    print_error(module_name, lineNumber, functonName, str, " -VCAL- ");
}




}//TDebug


}//c5r
