#ifndef JSONPARSER_H
#define JSONPARSER_H
#include<jsonparser/JsonParser.h>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class JsonApp{
	public:
		JsonApp(const string& filename);
		~JsonApp();
		void readJsonFile();
		void displayInfo();
		void displayAllDetails();
	private:
		string filepath;
		string jsonContent;
	
};
#endif
