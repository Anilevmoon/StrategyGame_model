#ifndef TUNIT_H
#define TUNIT_H


#include <EntityPart/IEntity.h>
#include <Prototypes/TUnitPrototype.h>
#include <Enums/NOwner.h>
#include <Enums/NEntityType.h>


class TUnit : public IEntity {
	public:
	TUnit();
	virtual ~TUnit()=default;

	public:
	void DestroyEntity() override;


	public:
	virtual void SetEntityPrototype(NEntityType type) override;
	void ChangeOwner(NOwner own) override;
	void ApplyDamage(float damage) override;
	void SetCoordinates(SMapPoint) override;
	void SetRotation(int rotation) override;

	public:
	NOwner& Owner() override;
	float Health() override;
	int Rotation() override;
	float Armor();
	float GetAttack();

	public:
	std::shared_ptr<TUnitPrototype> m_pPrototype = nullptr;
	
	protected:
	float m_xDynamicAttack = 0.f;
	float m_fDynamicArmor = 0.5f;
};

#endif //TUNIT_H