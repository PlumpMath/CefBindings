#include "stdafx.h"
#include "V8_handler.h"


V8Handler::V8Handler()
{
}


V8Handler::~V8Handler()
{
}


bool V8Handler::Execute( const CefString& name,
	CefRefPtr<CefV8Value> object,
	const CefV8ValueList& arguments,
	CefRefPtr<CefV8Value>& retval,
	CefString& exception )
{
	CEF_REQUIRE_RENDERER_THREAD();

	// realization of cppmethod
	if( name == "searchInDocs" )
	{
		if( arguments.size() == 1 && arguments[0]->IsString() )
		{
			onSearchButton( arguments[0]->GetStringValue().ToWString() );
		}
		return true;
	}

	//// realization of register method
	//if( name == "register" )
	//{
	//	LOG( INFO ) << "register";
	//	if( arguments.size() == 1 && arguments[0]->IsFunction() )
	//	{
	//		m_callbackFunction = arguments[0];
	//		m_callbackContext = CefV8Context::GetCurrentContext();
	//		return true;
	//	}
	//}

	return false;
}