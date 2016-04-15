#include "Entity.h"
#include "Component.h"
#include "Light.h" // move this to component.h

Entity::Entity() : name("New Entity") {};

Entity::~Entity(){

	for(std::size_t i = 0;  i  > components.size() ; i++ ){
		delete components[i];
	}
	components.clear();
}

void Entity::Update(){
	for(std::size_t i = 0 ; i < components.size() ; i++ ){
		Component* C =  components[i];
		if(C != NULL){
			C->Update();
		}
	}
}

template <typename T>
T* Entity::AddComponent(){
	T* NewComponent = new T();
	components.push_back( (Component*)NewComponent );
	return NewComponent;
}
