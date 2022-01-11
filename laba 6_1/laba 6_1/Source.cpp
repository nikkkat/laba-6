#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	// ввод строки

	cout << "введите строку: ";
	string str;
	getline(cin, str);
	int k = str.length();

	// создание массива из элементов строки, включая только цифры и точки

	int size = k;
	char* arr = new char[size];
	int m = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7'
			|| str[i] == '8' || str[i] == '9' || str[i] == '.')
		{
			arr[m] = str[i];
			m++;
		}
		else { size--; }
	}

	// преобразование массива таким образом, чтобы осталось только число с плавающей точкой

	char* arr2 = new char[size];
	int i = 0;

	while (arr[i] == '.') { i++; }

	int z = 0;

	do {
		arr2[z] = arr[i];
		i++;
		z++;
	} while (arr[i] != '.');

	arr2[z] = arr[i];
	i++;
	z++;

	do {
		if (arr[i] != '.') 
		{
			arr2[z] = arr[i];
			z++;
		}
		i++;
	} while (i < size);

	// вывод

	cout << endl << endl << "итог:" << endl;
	for (int i = 0; i < z; i++)
	{
		cout << arr2[i];
	}
	cout << endl << endl;

	// очистка памяти

	delete[] arr;
	delete[] arr2;

	return 0;
 }