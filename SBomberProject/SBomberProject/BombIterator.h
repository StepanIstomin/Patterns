#pragma once

#include <vector>

#include "Bomb.h"

using namespace std;

class BombIterator
{
public:
	BombIterator(const vector<DynamicObject*>& ref) : vecDynamicObj(ref), curIndex(-1), ptr(nullptr) { ++(*this); }
	void reset();
	BombIterator& operator++();
	BombIterator& operator--();
	DynamicObject* operator*();
	bool operator==(BombIterator it);
	bool operator!=(BombIterator it);

private:
	const vector<DynamicObject*>& vecDynamicObj;
	int curIndex;
	DynamicObject* ptr;
};