#ifndef CRX_BASE_TXTESTH_H_H
#define CRX_BASE_TXTESTH_H_H

#include <string>
#include <map>


namespace crx {

	namespace TDebug {

		// базовый класс для автотеста
		class TXTest {
			public:
			TXTest()=default;
			virtual ~TXTest()=default;

			public:
			void Assert(bool ok, const std::string& expression);
			void RunTest();

			public:
			virtual void Test()=0;// собственно сам тест

			public:
			static void ClearStats();
			static void ShowStats();
			static bool IsAllOk();

			public:
			static void RunTest(TXTest* t);
			static void RunTest(const std::string& n);

			protected:
			std::string m_sName;

			public:
			static inline std::map<std::string, TXTest*> sTestRegistry;
		};

		template <class TestType>
		struct TestRegistry {
			TestRegistry(const std::string& name) {
				TXTest::sTestRegistry.emplace(name, new TestType);
			}
		};

	}//TDebug

}//crx

#define AUTOTEST_BODY(...) \
    static inline crx::TDebug::TestRegistry<__VA_ARGS__> __testable{#__VA_ARGS__}; \
    virtual void Test() override

#define RUN_AUTOTEST(...) crx::TDebug::TXTest::RunTest(__VA_ARGS__);

#define RUN_ALLAUTOTESTS(...) \
    for(auto& [name, test]:crx::TDebug::TXTest::sTestRegistry) crx::TDebug::TXTest::RunTest(test);

#endif
