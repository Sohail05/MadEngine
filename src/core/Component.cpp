#include "Component.h"
#include "Entity.h"

Component::Component(Entity* parent){
	parent_ = parent;
}

Component::~Component(){}

Entity* Component::GetParent(){
	return parent_;
}

std::string Component::GetType()
{
	return typeid(*this).name();
}
