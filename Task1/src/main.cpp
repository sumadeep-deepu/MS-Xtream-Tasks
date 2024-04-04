#include<iostream>
#include "array.h"
using namespace std;
int main(){
	int size,choice;
	cout<<"enter the size of array : ";
	cin>>size;
	Arrays array(size);
	do{
		cout<<"enter the option you want or '0' to exit : "<<endl;

		cout<<"1.insert elements"<<endl;
		cout<<"2.sum of array elements"<<endl;
		cout<<"3.maxValue"<<endl;
		cout<<"4.minValue"<<endl;
		cout<<"5.avg"<<endl;
		cout<<"6.search element"<<endl;
		cout<<"7.sort the array"<<endl;
		cout<<"8.print even numbers"<<endl;
		cout<<"9.print odd numbers"<<endl;
		cout<<"10.display elements"<<endl;

		cin>>choice;

		switch(choice){
			case 0:
				return 1;
			case 1:
				int value;
				cout<<"enter the value : ";
				cin>>value;
				array.insert(value);
				break;
			case 2:
				array.sumOfArray();
				break;
			case 3:
				cout<<"the max value in the array is : "<<array.maxValue()<<endl;
				break;
			case 4:
				cout<<"the min value in the array is: "<<array.minValue()<<endl;
				break;
			case 5:
				array.average();
				break;
			case 6:
				int element;
				cout<<"enter the element to search : ";
				cin>>element;
				array.search(element);
				break;
			case 7:
				array.sort();
				break;
			case 8:
				cout<<"the even numbers in the array are : "<<endl;
				array.printEvenNumbers();
				break;
			case 9:
				cout<<"the odd numbers in the array are : "<<endl;
				array.printOddNumbers();
				break;
			case 10:
				cout<<"the elements in the array are : "<<endl;
				array.display();
				cout<<endl;
				break;
			default:
				cout<<"please choose the correct option!! and try again "<<endl;
		}
	}while(true);

	return 0;
}






