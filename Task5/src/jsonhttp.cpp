#include "httpJson.h"

jsonhttp::jsonhttp(string &jsonpath,string& config):SBU2WebService(){
	jsondata=new JsonApp(jsonpath);
	configdata=new JsonApp(config);
	configObject =configdata->getObject();
}
jsonhttp::~jsonhttp(){
	delete jsondata;
	delete configdata;
}
void jsonhttp::onInvalidJSONRequest(HTTPServerRequest *request,HTTPConnection *connection,string &rawRequest){
	cout<<"recived Request : "<<rawRequest<<endl;
	string infomsg,infoID;
	infoID=configObject["Response_onInvalidJson"]["infoID"];
	infomsg=configObject["Response_onInvalidJson"]["infomsg"];
	MSFRequest* msfreq=new MSFRequest(rawRequest);
	MSFResponse* err=new MSFResponse(msfreq);
	string errormsg="INVALID JSON request"+rawRequest;
	err->addToData("error",errormsg);
	err->setInfoID(infoID);
	err->setInfoMsg(infomsg);
	err->setSvcName(configObject["Response_onInvalidJson"]["svcName"]);
	err->setSvcGroup(configObject["Response_onInvalidJson"]["svcGroup"]);
	sendResponse(err,connection);
	connection->release();
}
void jsonhttp::onPostProcessRequest(MSFRequest *msfRequest,MSFResponse *msfResponse,HTTPConnection *connection){
	cout<<"recived Request"<<endl;
	string request=msfRequest->toString();
	JsonParser parser(request);
	JsonObject reqObject=parser.getJsonObject();

	if(reqObject.hasKey(configObject["Response_onPostProcessRequest"]["key"])){
		string content=reqObject[configObject["Response_onPostProcessRequest"]["key"]];

		if(content==configObject["Response_onPostProcessRequest"]["value1"]){
			reqObject=jsondata->getObject();
			msfResponse->addToData("all",reqObject);
			cout<<"Applications : "<<reqObject.toString()<<endl;
		}else if(content==configObject["Response_onPostProcessRequest"]["value2"]){
			reqObject=jsondata->getObject();
			msfResponse->addToData("app",reqObject["app"]);
			cout<<reqObject.toString()<<endl;
		}else if(content==configObject["Response_onPostProcessRequest"]["value3"]){
			reqObject=jsondata->getObject();
			msfResponse->addToData("info",reqObject["info"]);
			cout<<reqObject.toString()<<endl;
		}
		else{
			cerr<<"Invalid content "<<endl;
			string infoid=configObject["Response_onPostProcessRequest"]["infoid"];
			string infomsg=configObject["Response_onPostProcessRequest"]["infomsg"];

			msfResponse->setInfoID(infoid);
			msfResponse->setInfoMsg(infomsg);
		}
	}
	msfResponse->setSvcName(configObject["Response_onPostProcessRequest"]["svcName"]);
	msfResponse->setSvcGroup(configObject["Response_onPostProcessRequest"]["svcGroup"]);
	cout<<msfResponse->toString()<<endl;
	sendResponse(msfResponse,connection);
	connection->release();
}
