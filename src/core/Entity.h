#ifndef ENTITY_H
#define ENTITY_H

#include "Transform.h"
#include "Component.h"
#include "../Graphics/Renderer.h"
#include "../Common/String.h"
#include <vector>

using namespace MAD;

class Entity {

public:

	String name;
	Transform transform;
	std::vector<Component*> components;

	Entity();
	~Entity();

	void Update();

	template <typename T>
	T* AddComponent();

private:

};

#endif
