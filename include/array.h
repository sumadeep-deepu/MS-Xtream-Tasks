#ifndef ARRAY_I
#define ARRAY_H
#include<iostream>
using namespace std;
class Arrays{
	private:
		int size,count,sum;
		int* arr;
	public:
		Arrays(int size);
		void insert(int value);
		void display();
		void sumOfArray();
		int maxValue();
		int minValue();
		void average();
		void search(int value);
		void sort();
		void printEvenNumbers();
		void printOddNumbers();
};
#endif

