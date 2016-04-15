#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Entity;
class Component{
public:

	bool active;

	Component(Entity* parent);
	Component(){};
	virtual ~Component();

	virtual void Update()=0;
	virtual void Enable()=0;
	virtual void Disable()=0;

	Entity* GetParent();
	std::string GetType();

private:
	Entity* parent_;
};

#endif
