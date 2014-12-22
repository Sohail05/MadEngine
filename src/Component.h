#ifndef COMPONENT_H
#define COMPONENT_H

//Need to find a way to get back components from upper class!!!


class Component{
public:

	bool Active;
	
	Transform* transform;

	virtual void Update()= 0 ;
	virtual void Enable()= 0 ;
	virtual void Disable()= 0 ;


private:


};



#endif