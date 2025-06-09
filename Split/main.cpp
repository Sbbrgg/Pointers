#include<iostream>
using namespace std;

//#define FIRST_VARIANT
//#define SECOND_VARIANT
#define CLASS_VARIANT

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef FIRST_FARIANT
	const int n = 10;
	int arr[n], count = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			count++;
		}
	}
	int* even = new int[count];
	int* odd = new int[n - count];
	int index_for_even = 0;
	int index_for_odd = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[index_for_even] = arr[i];
			index_for_even++;
		}
		else
		{
			odd[index_for_odd] = arr[i];
			index_for_odd++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl << endl;
	for (int i = 0; i < index_for_even; i++)
	{
		cout << even[i] << "\t";
	}
	cout << endl << endl;
	for (int i = 0; i < index_for_odd; i++)
	{
		cout << odd[i] << "\t";
	}

	delete[] even;
	delete[] odd;
#endif // FIRST_VARIANT

#ifdef SECOND_FARIANT
	const int n = 10;
	int arr[n], rand_value, count = 0, count_for_even = 0, count_for_odd = 0;
	for (int i = 0; i < n; i++)
	{
		rand_value = rand() % 100;
		if (rand_value % 2 == 0)
		{
			count++;
			arr[count_for_even] = rand_value;
			count_for_even++;
		}
		else
		{
			arr[n - 1 - count_for_odd] = rand_value;
			count_for_odd++;
		}
	}
	cout << "Основной массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	int* even = new int[count_for_even];
	int* odd = new int[count_for_odd];
	int index_for_even = 0, index_for_odd = 0;


	for (int i = 0; i < n; i++)
	{
		if (i < count_for_even)even[index_for_even++] = arr[i];
		else odd[index_for_odd++] = arr[i];
	}
	cout << "Чётные элементы массива: ";
	for (int i = 0; i < index_for_even; i++)
	{
		cout << even[i] << "\t";
	}
	cout << endl;
	cout << "Нечётные элементы массива: ";
	for (int i = 0; i < index_for_odd; i++)
	{
		cout << odd[i] << "\t";
	}

	delete[] even;
	delete[] odd;
#endif // SECOND_VARIANT
#ifdef CLASS_VARIANT
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_count++;
		else odd_count++;
	}
	cout << "Количество четных элементов: " << even_count << endl;
	cout << "Количество нечетных элементов: " << odd_count << endl;

	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];
	}

	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

	delete[] odd_arr;
	delete[] even_arr;
#endif // CLASS_VARIANT

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
