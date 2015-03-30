#include "Component.h"
#include "Entity3D.h"

Component::Component(Entity3D* parent){

	parent_ = parent;

}

Component::~Component(){
}


Entity3D* Component::GetParent(){

	return parent_;
}



std::string Component::GetType()
{
	return typeid(*this).name() ;
}

