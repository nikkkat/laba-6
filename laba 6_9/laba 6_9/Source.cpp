#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	// ���� ������

	cout << "������� ������: ";
	string str;
	getline(cin, str);
	int k = str.length();

	// ������ ��������� � �������� � ������ char

	char* a = new char[k];
	int m = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' ||
			str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
			a[m] = str[i];
			m++;
		}
	}

	// �������� ������� int �� ���������� ������� char

	int* arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = a[i] - '0';
	}

	// ���� ����� ���� �����, ����� ����������, ������� ������

	int sum = 0;

	for (int i = 0; i < m; i++)
	{
		sum += arr[i];
	}

	cout << endl << "����� ���� �����: " << sum << endl;

	delete[] a;
	delete[] arr;

	return 0;
}