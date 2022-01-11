#include <iostream>
#include <cmath>
using namespace std;

int int_input()
{
	int k = 0;
	cin >> k;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "enter correct input: ";
		cin >> k;
	}

	return k;
}

double double_input()
{
	double k = 0;
	cin >> k;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "enter correct input: ";
		cin >> k;
	}

	return k;
}

void int_to_string(int a)
{
	int arr[10];
	char str[10];
	char* p = str;

	int k = 0;
	while (a != 0)
	{
		arr[k] = a % 10;
		a /= 10;
		k++;
	}

	for (int i = k -1; i > -1; i--)
	{
		p[i] = static_cast<char>(arr[i] + 48);
		cout << *(p + i);
	}
	cout << endl;
}

int string_to_int(char* p1)
{
	int len = 0;
	while (p1[len] != '\0')
	{
		len++;
	} 
	
	int num = 0;
	int k = len - 1;
	
	int* a = new int[len];
	for (int i = 0; i < len; i++)
	{
		a[i] = static_cast<int>(p1[i] - 48);
		num += static_cast<int>(a[i] * pow(10, k));
		k--;
	}
	
	delete[] a;
	return num;
}

void real_to_string(double b)
{
	char* p = new char[15];

	double w;
	double f;

	int* first_a = new int[15];
	int* last_a = new int[15];

	f = modf(b, &w);

	int ww = static_cast<int>(w);
	int k = 0;
	while (ww != 0)
	{
		first_a[k] = ww % 10;
		ww /= 10;
		k++;
	}

	f *= 1e9;
	int ff = static_cast<int>(f);
	int n = k;

	if (ff % 10 != 0)
	{
		ff++;
	}

	while (ff % 10 == 0)
	{
		ff /= 10;
	}

	while (ff != 0)
	{
		last_a[k] = ff % 10;
		ff /= 10;
		k++;
	}

	int x = 0;

	for (int i = n - 1; i > -1; i--)
	{
		p[x] = static_cast<char>(first_a[i] + 48);
		cout << p[x];
		x++;
	}
	cout << ".";
	for (int i = k - 1; i > -1; i--)
	{
		p[x] = static_cast<char>(last_a[i] + 48);
		cout << p[x];
		x++;
	}
	cout << endl;

	delete[] p;
	delete[] first_a;
	delete[] last_a;
}

double string_to_real(char* p2)
{
	int index = 0;
	int len = 0;
	while (p2[len] != '\0')
	{
		if (p2[len] == '.') { index = len; }
		len++;
	}

	double real = 0.0;
	int k = index - 1;
	int* arr = new int[len - 1];

	for (int i = 0; i < index; i++)
	{
		arr[i] = static_cast<double>(p2[i] - 48);
		real += arr[i] * pow(10, k);
		k--;
	}
	k = -1;
	for (int i = index + 1; i < len - 1; i++)
	{
		arr[i] = static_cast<double>(p2[i] - 48);
		real += arr[i] * pow(10, k);
		k--;
	}

	delete[] arr;
	return real;
}

int main()
{
	cout << "enter number to remake it to string: ";
	int a = int_input();
	cout << endl << "result: " << endl;
	int_to_string(a);

	cout << endl << "enter string (9 numbers) to remake it to number: ";
	char str1[9];
	cin.ignore();
	cin.getline(str1, 9);
	char* p1 = str1;
	cout << endl << "result: " << endl;
	string_to_int(str1);

	cout << endl << "enter real number to remake it to string: ";
	double b = double_input();
	cout << endl << "result: " << endl;
	real_to_string(b);

	cout << endl << "enter string to remake it to real number: ";
	char str2[20];
	cin.ignore();
	cin.getline(str2, 20);
	char* p2 = str2;
	cout << endl << "result: " << endl;
	string_to_real(str2);
	cout << endl;

	return 0;
}