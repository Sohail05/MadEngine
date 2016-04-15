#ifndef ENTITY_H
#define ENTITY_H

#include "Transform.h"
#include "Component.h"
#include "Mesh.h"
#include "Render.h"
#include "common\String.h"
#include <vector>

using namespace MAD;

class Entity {

public:

	String name;
	Transform transform;
	vector<Component*> components;

	Entity();
	~Entity();

	void Update();

	template <typename T>
	T* AddComponent();

private:

};

#endif
