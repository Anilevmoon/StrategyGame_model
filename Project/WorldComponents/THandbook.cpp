#include <CRX/Reflection/TReflectionImplDefs.h>

#include <WorldComponents/THandbook.h>

BEGIN_REFLECTION_TABLE(THandbook, TObject)
_ADD_PROPERTY(UnitPrototypes);
_ADD_PROPERTY(BuffPrototypes);
_ADD_PROPERTY(PlayerPrototypes);
_ADD_PROPERTY(WorldPrototypes);
_ADD_PROPERTY(MapPrototypes);
_ADD_PROPERTY(BuildingPrototypes);

END_REFLECTION_TABLE();

THandbook* Handbook() {
	static THandbook* handbook = new THandbook();
	return handbook;
}

void THandbook::Load() {
	std::ifstream file(FileName);
	std::string data(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{});

	crx::TReflectionTwoStepXMLDeserializer deserializer;

	std::any handbook;
	deserializer.Load(handbook, data);

	*this = *std::any_cast<THandbook*>(handbook);
}

void THandbook::Save() {
	crx::TReflectionTwoStepXMLSerializer serializer;

	std::any handbook;
	serializer.Save("THandbook", this);

	std::ofstream file(FileName);
	file<<serializer.Data();
}

std::shared_ptr<TUnitPrototype> THandbook::GetUnitPrototypeByName(const std::string& name) {
	auto it = UnitPrototypes.find(name);
	if(it!=UnitPrototypes.end()) { return it->second; }
	// return default
	return std::make_shared<TUnitPrototype>();
}

std::shared_ptr<TMapPrototype> THandbook::GetMapPrototypeByName(const std::string& name) {
	auto it = MapPrototypes.find(name);
	if(it!=MapPrototypes.end()) { return it->second; }
	// return default
	return std::shared_ptr<TMapPrototype>();
}
