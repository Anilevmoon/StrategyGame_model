#include <CRX/Reflection/TReflectionImplDefs.h>

#include <WorldComponents/THandbook.h>

BEGIN_REFLECTION_TABLE(THandbook, TObject)
_ADD_PROPERTY(UnitPrototypes);
END_REFLECTION_TABLE();

THandbook* Handbook() {
    static THandbook* handbook = new THandbook();
    return handbook;
}
