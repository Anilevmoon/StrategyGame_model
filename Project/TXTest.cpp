#include "TDebug.h"
#include "TXTest.h"

namespace crx {

	namespace TDebug {

		static const std::string RED="\x1B[31m";
		static const std::string GRN="\x1B[32m";
		//static const string YEL    = "\x1B[33m";
		//static const string BLU    = "\x1B[34m";
		//static const string MAG    = "\x1B[35m";
		//static const string CYN    = "\x1B[36m";
		//static const string WHT    = "\x1B[37m";
		static const std::string RESET="\x1B[0m";
		//static const string BLINK  = "\x1B[5m";

		static int s_iTotalTests=0;
		static int s_iSuccessTests=0;

		void TXTest::RunTest() {
			//Test();
			//return;
			try {
				Test();
			}
			catch(std::exception& ex) {
				Assert(false, "Raise exception \""+std::string(ex.what())+"\"");
			}
			catch(...) {
				Assert(false, "Raise unknown exception");
			}
		}

		void TXTest::Assert(bool ok, const std::string& mes) {
			if(s_iTotalTests==0) TDebug::PrintRaw("\n");

			auto s=m_sName+" - "+mes+" - ";

			if(ok) {
				s+="Ok";
			} else {
#ifdef __GNUC__
				s+=RED+"Fail"+RESET;
#else
				s+="Fail";
#endif

			}

			TDebug::PrintRaw(s);

			s_iTotalTests++;
			if(ok) s_iSuccessTests++;
		}

		void TXTest::ClearStats() {
			s_iTotalTests=0;
			s_iSuccessTests=0;
		}

		void TXTest::ShowStats() {
			int errs=s_iTotalTests-s_iSuccessTests;
			auto serr="Errors:  "+std::to_string(errs);
			auto ssuc="Success: "+std::to_string(s_iSuccessTests);

#ifdef __GNUC__
			if(errs>0) {
				serr=RED+serr+RESET;
			} else {
				ssuc=GRN+ssuc+RESET;
			}
#endif

			std::string s="\n-------------------------------\n";
			s+=serr+"\n";
			s+=ssuc+"\n";
			s+="Total:   "+std::to_string(s_iTotalTests)+"\n\n";
			TDebug::PrintRaw(s);
		}

		bool TXTest::IsAllOk() { return s_iTotalTests>0&&s_iTotalTests==s_iSuccessTests; }

		void TXTest::RunTest(TXTest* t) {
			t->RunTest();
			delete t;
		}

		void TXTest::RunTest(const std::string& n) {
			auto t=sTestRegistry[n];
			if(!t) _ERROR("Cannot find test with name: "<<n);
			t->RunTest();
		}

	}//TDebug

}//crx
