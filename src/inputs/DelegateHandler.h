#include <Awesomium/WebCore.h>
#include <Awesomium/STLHelpers.h>

#include "js_delegate.h"
#include <map>

#include <iostream>

//Leave this until Offscreen view is properly implemented

using namespace Awesomium;

typedef std::pair<int, Awesomium::WebString> ObjectMethodKey;
typedef std::map<ObjectMethodKey, JSDelegate> BoundMethodMap;
typedef std::map<ObjectMethodKey, JSDelegateWithRetval> BoundMethodWithRetvalMap;
BoundMethodMap bound_methods_;
BoundMethodWithRetvalMap bound_methods_with_retval_;

class delegator : public Awesomium::JSMethodHandler{
public:

	delegator(){}
	//Todo: there is no actual implementation/use !
		delegator(JSObject& app_object){
	}

	void OnMethodCall(WebView* caller,unsigned int remote_object_id, const WebString& method_name,const Awesomium::JSArray& args) {
		// Find the method that matches the object id + method name
		std::map<ObjectMethodKey, JSDelegate>::iterator i =
			bound_methods_.find(ObjectMethodKey(remote_object_id, method_name));

		// Call the method
		if (i != bound_methods_.end())
			i->second(caller, args);
	}

	Awesomium::JSValue OnMethodCallWithReturnValue(Awesomium::WebView* caller,
		unsigned int remote_object_id,
		const Awesomium::WebString& method_name,
		const Awesomium::JSArray& args) {
			// Find the method that matches the object id + method name
			std::map<ObjectMethodKey, JSDelegateWithRetval>::iterator i =
				bound_methods_with_retval_.find(ObjectMethodKey(remote_object_id, method_name));

			// Call the method
			if (i != bound_methods_with_retval_.end())
				return i->second(caller, args);

			return Awesomium::JSValue::Undefined();
	}


	void Bind(Awesomium::JSObject& object,const Awesomium::WebString& name, JSDelegate callback){

		// We can't bind methods to local JSObjects
		if (object.type() == Awesomium::kJSObjectType_Local){
			return;
		}

		object.SetCustomMethod(name, false);

		ObjectMethodKey key(object.remote_id(), name);
		bound_methods_[key] = callback;

	}//end bind

};//end class




//Callbacks

/*

//JS CALLBACKS

JSValue result = view->CreateGlobalJavascriptObject(WSLit("app"));
JSObject& app_object = result.ToObject();
delegator deler(app_object);

deler.customBind( app_object , WSLit("WebViewResize") , &WebViewResize );
deler.customBind( app_object , WSLit("ChangeColor") ,  &ChangeColor );
deler.customBind( app_object , WSLit("SetPosition") ,  &SetPosition );

view->set_js_method_handler(&deler);
//




void WebViewResize(WebView* caller, const JSArray& args){

WebViewWidth = args[0].ToInteger();

}

void ChangeColor(WebView* caller, const JSArray& args){

	R=args[0].ToInteger();
	G=args[1].ToInteger();
	B=args[2].ToInteger();

}

glm::vec3 position;

void SetPosition(WebView* caller, const JSArray& args){

position.x= (float)args[0].ToInteger();
position.z= (float)args[2].ToInteger();
position.y= (float)args[1].ToInteger();

std::cout << "PositionSet :" << position.x;

}

*/
