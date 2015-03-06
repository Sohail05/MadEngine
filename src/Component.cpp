#include "Component.h"

Transform* Component::GetTransform(){

	return transform_;
}

void Component::SetTransform(Transform* transform){

	transform_ = transform;
}

std::string Component::GetType()
{
	return typeid(*this).name() ;
}

