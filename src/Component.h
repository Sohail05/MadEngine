#ifndef COMPONENT_H
#define COMPONENT_H

//Need to find a way to get back components from upper class ( if components will only ever be applied to Entity)
//Suggested ideas :
//#1 Add Entity Pointer to Transform Class
//#2 Add Entity Pointer to Component Class

class Component{
public:

	bool active;
 
	Transform* transform;

	virtual void Update()= 0 ;
	virtual void Enable()= 0 ;
	virtual void Disable()= 0 ;

private:

};

#endif