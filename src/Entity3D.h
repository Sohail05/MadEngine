#ifndef ENTITY3D_H
#define ENTITY3D_H

#include "Transform.h"
#include "Component.h"
#include "Mesh.h"
#include <vector>
#include <string>

class Entity3D {

public:


	std::string Name;
	Transform transform;
	std::vector<Component*> Components;


	void Update(){

		for(std::size_t i = 0 ; i < Components.size() ; i++ ){

			Components.at(i)->Update();
		}
	}



	void AddComponent(Component* C){

		C->transform = &transform ;
		Components.push_back( C );
	}


	//Overloading temp solution for easy components implimentation
	//void AddComponent(Mesh M){

	//	AddComponent( (Component*)&M );
	//}


private:


};






#endif