#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, const int value, const int index);
int* erase(int arr[], int& n, const int index);

int** push_row_back(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];	//Объявление динамического 

	FillRand(arr, n);
	Print(arr, n);

	int value;
	/*cout << endl << "Введите добавляемое значение: "; cin >> value;
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
	cout << endl << endl;*/

	int index;
	cout << "Введи добавляемое значение: "; cin >> value;
	while (true)
	{
		cout << "Введи индекс массива, куда вставить значение: "; cin >> index;
		if (index < 0 || index > n)cout << "Неправильный индекс" << endl;
		else break;
	}
	arr = insert(arr, n, value, index);
	Print(arr, n);

	while (true)
	{
		cout << "Введите индекс значения, которое хотите удалить из массива: "; cin >> index;
		if (index < 0 || index > n)cout << "Неправильный индекс" << endl;
		else break;
	}
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	/////////////////////////////////////////////////////////////////////
	/////		Объявление двумерного динамического массива			/////
	/////////////////////////////////////////////////////////////////////
	
	//1) Создаём массив указателей
	int** arr = new int* [rows] {};

	//2) Выделяем память под строки
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand()% 10000;
	Print(arr, rows, cols);
	/////////////////////////////////////////////////////////////////////
	/////		 Удаление двумерного динамического массива			/////
	/////////////////////////////////////////////////////////////////////

	//1) Сначала удаляются строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) Только теперь можно удалить массив указателей:
	delete[] arr;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand-minRand)+minRand;	//Через арифметику указателей и оператор разыменования
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
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

int* insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n+1; i++)
	{
		if (i < index)buffer[i] = arr[i];
		else if (i == index)buffer[i] = value;
		else buffer[i] = arr[i - 1];
	}
	delete[] arr;
	n++;
	return buffer;
	/*int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	n++;
	return buffer;*/
}
int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
	}
	delete[] arr;
	n--;
	return buffer;
	/*int* buffer = new int[--n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;*/
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) Создаём буфферный массив указателей нужного размера: 
	int** buffer = new int* [rows + 1];

	//2) Копируем адреса строк в новый массив: 
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем исходный массив указателей:
	delete[] arr;

	//4) Добавляем добавляемую строку:
	buffer[rows] = new int[cols] {};
		
	//5) После добавления строки, количество строк увеличивается на 1:
	rows++;

	//6) Возвращаем новый массив:
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаём буферную строку нужного размера: 
		int* buffer = new int[cols + 1] {};

		//2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];

		//3) Удаляем сходную строку:
		delete[] arr[i];

		//4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols++;
}