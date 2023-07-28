#ifndef TOBJECT_H
#define TOBJECT_H

#include <memory>
#include <CRX/Reflection/TReflectionObject.h>

class TObject : public crx::TReflectionObject {
	public:
	DECL_REFLECTION_TABLE();

	public:
	TObject()=default;
	virtual ~TObject()=default;
};

#endif // TOBJECT_H