#ifndef ENTITY3D_H
#define ENTITY3D_H

#include "Transform.h"
#include "Component.h"
#include "Mesh.h"
#include <vector>
#include <string>

using namespace std;

class Entity3D {

public:

	string Name;
	Transform transform;
	vector<Component*> Components;

	void Update(){

		for(std::size_t i = 0 ; i < Components.size() ; i++ ){

			Components.at(i)->Update();
		}
	}


	//Todo: Implement a way to get component of type X
	void AddComponent(Component* C){

		C->transform = &transform ;
		Components.push_back( C );
	}



private:


};






#endif