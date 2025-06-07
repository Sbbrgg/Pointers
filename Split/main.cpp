#include<iostream>
using namespace std;

//#define FIRST_FARIANT
//#define SECOND_FARIANT

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
#endif // FIRST_FARIANT

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
#endif // SECOND_FARIANT

}