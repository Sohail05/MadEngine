#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Entity3D;
class Component{
public:

	bool active;

	Component(Entity3D* parent);
	Component(){};
	virtual ~Component();

	virtual void Update()=0;
	virtual void Enable()=0;
	virtual void Disable()=0;

	Entity3D* GetParent();
	std::string GetType();

private:
	Entity3D* parent_;
};

#endif
