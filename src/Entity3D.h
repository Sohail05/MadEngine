#ifndef ENTITY3D_H
#define ENTITY3D_H

#include "Transform.h"
#include "Component.h"
#include "Mesh.h"
#include "Render.h"
#include <vector>
#include <string>

using namespace std;

class Entity3D {

public:

	string name;
	Transform transform;
	vector<Component*> components;

	Entity3D();
	~Entity3D();

	void Update();

	template <typename T>
	T* AddComponent();

private:

};

#endif
