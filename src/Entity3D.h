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

	string name;
	Transform transform;
	vector<Component*> components;

	Entity3D(){};

	~Entity3D(){

		components.clear();

	}



	void Update(){
		for(std::size_t i = 0 ; i < components.size() ; i++ ){

			components.at(i)->Update();


		}

	}


	void AddComponent(Component* C){

		C->SetTransform(&transform);
		components.push_back( C );

	}



	/*

	template <typename T>
	T* AddComponent(){


	T* C = new T();
	C->SetTransform(&transform);
	components.push_back( (Component*)C );

	return (T*)&components.back();
	}


	template <typename T>
	T* GetComponent(){

	for(std::size_t i = 0 ; i < components.size() ; i++ ){

	if( typeid( T ).name() == typeid( components.at(i)).name()  ){
	return &components.at(i);
	}
	}

	return;
	}

	*/
private:

};

#endif