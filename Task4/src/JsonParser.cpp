#include "JsonParser.h"
#include<iostream>

JsonApp::JsonApp(const string& filename){
	this->filepath = filename;
}

JsonApp::~JsonApp(){}

void JsonApp::readJsonFile(){
	ifstream file(filepath);
	if(!file.is_open()){
		cerr<<"error unable to open json file"<<endl;
		return;
	}
	ostringstream ss;
	ss<<file.rdbuf();
	jsonContent=ss.str();
	file.close();
}
void JsonApp::displayInfo(){
	string key;
	cout << "Enter key : ";
	cin >> key ;
	JsonParser parser(jsonContent);
	JsonObject jsonObject = parser.getJsonObject();
	JsonObject jsonInfoObject = jsonObject["info"];
	size_t size = jsonInfoObject.size();
	bool flag=false;
	if( key == "all" || key == "ALL"){
		flag=true;
		for(size_t i = 0; i< size ; i++){
			cout << "Key name : " << jsonInfoObject[i]["key"] <<endl;
			cout <<"Action name: " << jsonInfoObject[i]["value"]["action"] << endl;
			cout << "Message name: " << jsonInfoObject[i]["value"]["msg"] << endl;
		}
	}else{
		for(size_t i = 0 ; i < size ; i++){
			if(key == jsonInfoObject[i]["key"]){
				flag=true;
				cout<<"Key name :"<<jsonInfoObject[i]["key"]<<endl;
				cout<<"Action name : "<<jsonInfoObject[i]["value"]["action"]<<endl;
				cout<<"Messge name: "<<jsonInfoObject[i]["value"]["msg"]<<endl;
				break;
			}

		}
	}
		if(flag==false){
			cout<<"key not found please try again"<<endl;
		}


};
void JsonApp::displayAllDetails(){
	JsonParser parser(jsonContent);
	JsonObject jsonObject=parser.getJsonObject();
	JsonObject jsonAppObject=jsonObject["app"];
	size_t size=jsonAppObject.size();
	for(size_t i=0;i<size;i++){
		cout<<"key : "<<jsonAppObject[i]["key"]<<endl;
		cout<<"value : "<<jsonAppObject[i]["value"]<<endl;
	}
}





