#include "Entity3D.h"
#include "Component.h"


Entity3D::Entity3D() : name("New Entity") {



};

Entity3D::~Entity3D(){

	for(std::size_t i = 0;  i  > components.size() ; i++ ){

		delete components[i];

	}
	components.clear();

}

void Entity3D::Update(){

	for(std::size_t i = 0 ; i < components.size() ; i++ ){

		Component* C =  components[i];

		if(C != NULL){

			C->Update();

		}

	}

}


template <typename T>
T* Entity3D::AddComponent(){

	T* NewComponent = new T();

	components.push_back( (Component*)NewComponent );

	return NewComponent;
}
