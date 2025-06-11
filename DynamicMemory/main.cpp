#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];	//Объявление динамического 

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << endl << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << endl << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Удаляем последнее значение" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаляем первое значение" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;	//Через арифметику указателей и оператор разыменования
	}

}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";		//Через оператор индексирования (Subscript operator)
	}
	cout << endl;
}

int* push_back(int arr[], int& n, const int value) 
{
	//1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем исходный массив
	delete[] arr;

	//4) Подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	buffer = nullptr;	//nullptr - указатель на ноль

	//5) Только после всего вышенаписанного в массив 'arr' появляется элемент, 
	// в который можно сохранить добавляемое значение

	arr[n] = value;
	//6) После добавления элемента в массив, количество его элементов увеличивается на один
	n++;

	//7) Mission complete - знчение добавлено
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}

	delete[] arr;

	arr = buffer;
	buffer = nullptr;
	arr[0] = value;

	n++;

	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}

