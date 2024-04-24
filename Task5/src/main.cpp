#include "httpJson.h"
#include<iostream>

using namespace std;
int main(int argc,char* argv[]){
	if(argc!=2){
		cerr<<"Usage : "<<argv[0]<<"<JSON_file>"<<endl;
		return 1;
	}
	string configpath=argv[1];
	JsonApp config(configpath);
	JsonObject object=config.getObject();
	string jsonpath=object["Json_filepath"];
	jsonhttp *server=new jsonhttp(jsonpath,configpath);

	map<string,SBU2WebService *>* jWebService =new map<string,SBU2WebService *>;

	string end_url="/Config/Base/1.0.0";
	int load=1;
	int port=12345;
	cout<<"end_url : "<<end_url<<"\tLoad : "<<load<<"\tPort : "<<port<<endl;
	(*jWebService)[end_url]=server;
	SBU2LoadBalancer *loadBalancer =new SBU2LoadBalancer(load,jWebService);
	SBU2HTTPServer *httpServer=new SBU2HTTPServer(port,loadBalancer);
	httpServer->run();
	while(true);
}
