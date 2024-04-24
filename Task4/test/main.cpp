#include <appparser/JsonParse.h>
#include<iostream>


using namespace std;
int main(){
	string filepath="config/jsonfile.json";
	JsonApp json(filepath);
	string key;
	int choice;
	while(true){
		cout<<"choose an option below to perform  : "<<endl;
		cout<<"1. Display info"<<endl;
		cout<<"2.Display all App details "<<endl;
		cout<<"3.exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<"enter key or ('all  for all app info')"<<endl;
				cin>>key;
				cout<<json.infoOperation(key)<<endl;
			}
			break;
			case 2:{
				string output=json.appDetailsOperation();
				cout<<output<<endl;
			}break;
			case 3:
				cout<<"Exiting";
				return 0;
			default:
				cout<<"please choose valid option"<<endl;
				break;
		}
	}
	return 0;
}


