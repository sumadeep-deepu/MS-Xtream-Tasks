#include <jsonparser/JsonParser.h>
int main(){
	string filepath="./config/jsonfile.json";
	JsonApp json(filepath);
	json.readJsonFile();
	int choice;
	while(true){
		cout<<"choose an option below to perform  : "<<endl;
		cout<<"1.info"<<endl;
		cout<<"2.app"<<endl;
		cout<<"3.exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				json.displayInfo();
				break;

			case 2:
				json.displayAllDetails();
				break;
			case 3:
				return 0;
			default:
				cout<<"please choose valid option"<<endl;
				break;
		}
	}
	return 0;
}


