#ifndef JSONPARSE_H
#define JSONPARSE_H
#include<jsonparser/JsonParser.h>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class JsonApp{
	public:
		JsonApp(const string& filename);
		JsonObject getObject();
		~JsonApp();
		void readJsonFile();
		string infoOperation(string& key);
		string appDetailsOperation();
	private:
		string filepath;
		string jsonContent;
		JsonObject obj;
};
#endif
