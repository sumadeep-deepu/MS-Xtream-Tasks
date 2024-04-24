#include "JsonParse.h"

JsonApp::JsonApp(const string& filename){
	this->filepath = filename;
	readJsonFile();
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
	JsonParser parser(jsonContent);
	obj = parser.getJsonObject();
	file.close();
}
JsonObject JsonApp::getObject(){
	return obj;
}

string JsonApp::infoOperation(string& key){
	JsonObject jsonInfoObject=obj["info"];
	if(key=="all"||key=="ALL"||key=="All"){
		string output;
		for(size_t i=0;i<jsonInfoObject.size();i++){
			output+="Key Name : "+ jsonInfoObject[i]["key"]+"\n";
			output+="Action Name : "+jsonInfoObject[i]["value"]["action"]+"\n";
			output+="Message Name : "+jsonInfoObject[i]["value"]["msg"]+"\n";

		}
		return output;
	}else{
		for(size_t i=0;i<jsonInfoObject.size();i++){
			if(key==jsonInfoObject[i]["key"]){
				string output;
				output+="Key Name : "+ jsonInfoObject[i]["key"]+"\n";
				output+="Action Name : "+jsonInfoObject[i]["value"]["action"]+"\n";
				output+="Message Name : "+jsonInfoObject[i]["value"]["msg"]+"\n";
				return output;
			}

		}
		return "Key not found please try again! \n";
	}
}

string JsonApp::appDetailsOperation(){
	JsonObject jsonAppObject=obj["app"];
	string output="Displaying all app details : \n";
	for(size_t i=0;i<jsonAppObject.size();i++){
		output+="Key"+jsonAppObject[i]["key"]+"\n";
		output+="Value"+jsonAppObject[i]["value"]+"\n";
	}
	return output;
}


