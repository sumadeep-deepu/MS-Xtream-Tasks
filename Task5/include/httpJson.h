#ifndef HTTP_JSON_H
#define HTTP_JSON_H

#include<iostream>
#include<sbu2webapp/SBU2WebService.h>
#include<sbu2webapp/SBU2HTTPServer.h>
#include<appparser/JsonParser.h>

using namespace SBU2;
using namespace UBACIPC;
using namespace std;

class jsonhttp : public SBU2WebService
{
	public:
		jsonhttp(string& jsonpath,string& config);
		~jsonhttp();
		void onInvalidJSONRequest(HTTPServerRequest *request,HTTPConnection *connection,string& rawRequest);
		void onPostProcessRequest(MSFRequest *msfRequest,MSFResponse *msfResponse,HTTPConnection *connection);
	private:
		JsonApp *jsondata;
		JsonApp *configdata;
		JsonObject request,response,configObject;
		string jsonpath,configpath;
};

#endif
