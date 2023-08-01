
#include <map>
#include <fstream>

#include <CRX/Base/TSingleton.h>
#include <CRX/Reflection/TReflectionTwoStepXMLSerializer.h>
#include <CRX/Reflection/TReflectionTwoStepXMLDeserializer.h>
#include <Prototypes/TBuffPrototype.h>
#include <Prototypes/TUnitPrototype.h>
#include <Prototypes/TPlayerPrototype.h>
#include <Prototypes/TWorldPrototype.h>

class THandbook : virtual public TObject {
    public:
    DECL_REFLECTION_TABLE();

    THandbook() {
    }
    virtual ~THandbook() {
    }
    public:
    void Load();
    void Save();

    std::shared_ptr<TUnitPrototype> GetUnitPrototypeByName(const std::string& name);

    public:
    std::map<std::string, std::shared_ptr<TWorldPrototype>> WorldPrototypes;
    std::map<std::string, std::shared_ptr<TMapPrototype>> MapPrototypes;
    std::map<std::string, std::shared_ptr<TPlayerPrototype>> PlayerPrototypes;
    std::map<std::string, std::shared_ptr<TUnitPrototype>> UnitPrototypes;
    std::map<std::string, std::shared_ptr<TBuildingsPrototype>> BuildingPrototypes;
    std::map<std::string, std::shared_ptr<TBuffPrototype>> BuffPrototypes;

    public:
    std::string FileName = "Handbook.xm";
};

THandbook* Handbook();