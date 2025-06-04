#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;		//вывод переменной "а" на экран
	cout << &a << endl;		//взятие адреса переменной "а" прямо при выводе
	cout << pa << endl;		//вывод адреса переменной "а", хранящего в указателе "pa"
	cout << pa << endl;		//разыменование указателя "ра", и вывод на экран значения по адресу
	cout << endl << endl;
	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << pb << endl;

	//int - 'int'
	//int* - указатель на 'int'
	//double - 'double'
	//double* - указатель на 'double'  
#endif // POINTERS_BASICS

	const int n = 5;
	short arr[n] = { 3, 5, 7, 3, 1 };
	cout << arr << endl;
	cout << &arr[0] << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}