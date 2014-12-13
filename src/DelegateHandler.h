#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>

#include "js_delegate.h"
#include <map>

#include <iostream>

using namespace Awesomium;


typedef std::pair<int, Awesomium::WebString> ObjectMethodKey;
typedef std::map<ObjectMethodKey, JSDelegate> BoundMethodMap;
typedef std::map<ObjectMethodKey, JSDelegateWithRetval> BoundMethodWithRetvalMap;
BoundMethodMap bound_methods_;
BoundMethodWithRetvalMap bound_methods_with_retval_;


class delegator : public Awesomium::JSMethodHandler{
public:


	delegator(){};

	delegator(JSObject& app_object){



	}


	void customBind( JSObject& app_object, WebString name , JSDelegate del ){

		Bind(app_object, name, del);

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
		if (object.type() == Awesomium::kJSObjectType_Local)
			return;

		object.SetCustomMethod(name, false);

		ObjectMethodKey key(object.remote_id(), name);
		bound_methods_[key] = callback;

	}//end bind

};//end class
