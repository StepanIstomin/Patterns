#pragma once
#include <vector>

#include "DynamicObject.h"

class DestroyableGroundObject;

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	void AddObserver(GameObject* gameObject);
	void RemoveObserver(DestroyableGroundObject*);

	DestroyableGroundObject* __fastcall CheckDestroyableObjects();

private:
	std::vector<DestroyableGroundObject*> groundObjects;
};

