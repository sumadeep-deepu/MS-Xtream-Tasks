#include "array.h"
Arrays::Arrays(int size):size(size),count(0),sum(0){
	arr=new int[size];
}
void Arrays::insert(int value){
	if(count<size){
		arr[count]=value;
		sum+=value;
	count++;	
	}
	else{
		cout<<"array is full"<<endl;
	}
}
void Arrays::display(){
	for(int i=0;i<count;i++){
		cout<<arr[i]<<" ";
	}
}
void Arrays::sumOfArray(){
	cout<<"the sum of array is : "<<sum<<endl;
}
int Arrays::maxValue(){
	int max=arr[0];
	for(int i=1;i<count;i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	return max;
}
int Arrays::minValue(){
	int min=arr[0];
	for(int i=1;i<count;i++){
		if(min>arr[i]){
			min=arr[i];
		}
	}
	return min;
}
void Arrays::average(){
	float avg=sum/count;
	cout<<"the average of elements is : "<<avg<<endl;
}
void Arrays::search(int value){
	for(int i=0;i<count;i++){
		if(value==arr[i]){
			cout<<"value found at "<<i<<" location : "<<value<<endl;
			break;
		
		}
	}
	cout<<"value not found"<<endl;
}
void Arrays::printEvenNumbers(){
	for(int i=0;i<count;i++){
		if(arr[i]%2==0){
			cout<<arr[i]<<endl;
		}
	}
}
void Arrays::printOddNumbers(){
	for(int i=0;i<count;i++){
		if(arr[i]%2!=0){
			cout<<arr[i]<<endl;
		}
	}
}
void Arrays::sort(){
	for(int i=0;i<count;i++){
		int min=i;
		for(int j=i+1;j<count;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		if(min!=i){
			int temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
	}
}






