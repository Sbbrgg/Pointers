#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a;	//компилятор сам неявно берёт адрес переменной "а", и записывает его в ссылку "ra"
	ra += 3;
	cout << ra << endl << endl;
	cout << &a << endl;
	cout << &ra << endl;
}