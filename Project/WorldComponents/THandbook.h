
#include <map>
#include <fstream>

#include <CRX/Base/TSingleton.h>
#include <CRX/Reflection/TReflectionTwoStepXMLSerializer.h>
#include <CRX/Reflection/TReflectionTwoStepXMLDeserializer.h>
#include <Prototypes/TUnitPrototype.h>

class THandbook : virtual public TObject {
    public:
    DECL_REFLECTION_TABLE();

    THandbook() {
    }
    virtual ~THandbook() {
    }
    public:
    void Load() {
        std::ifstream file(FileName);
        std::string data(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{});

        crx::TReflectionTwoStepXMLDeserializer deserializer;
        
        std::any handbook;
        deserializer.Load(handbook, data);

        *this = *std::any_cast<THandbook*>(handbook);
    }
    void Save() {
        crx::TReflectionTwoStepXMLSerializer serializer;

        std::any handbook;
        serializer.Save("THandbook", this);

        std::ofstream file(FileName);
        file<<serializer.Data();
    }

    //TUnitPrototype GetWorldPrototypeByName(const std::string& name) {
    //    auto it = UnitPrototypes.find(name);
    //    if(it!=UnitPrototypes.end()) {
    //        return it->second;
    //    }
    //                               // Вернуть дефолтное значение или обработать отсутствие прототипа
    //    return TUnitPrototype();
    //}

    public:
    //std::map<std::string, TWorldPrototype> WorldPrototypes;
    //std::map<std::string, TMapPrototype> MapPrototypes;
    //std::map<std::string, TPlayerPrototype> PlayerPrototypes;
    std::map<std::string, std::shared_ptr<TUnitPrototype>> UnitPrototypes;
    //std::map<std::string, TBuffPrototype> BuffPrototypes;

    public:
    std::string FileName = "Handbook.xm";
};

THandbook* Handbook();