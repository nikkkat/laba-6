#include <iostream>
using namespace std;

int fact(int a)				// ���������� ����������
{
	if (a == 1) 
	{ return 1; }
	else 
	{ return a * fact(a - 1); }
}

int main()
{
	// ���� �����, ���� ���������� ��������

	setlocale(LC_ALL, "ru");
	char str[14];
	cout << "������� �����: ";
	cin.getline(str, 14);

	// ���� ���������� �� �������, �����

	int res = fact(strlen(str));
	for (int i = 0; i < strlen(str); i++)
	{
		int s = 1;
		for (int j = i + 1; j < strlen(str); j++)
		{
			if (str[i] == str[j]) { s++; }
		}
		res /= s;
	}

	cout << endl << "���������� ��������: " << res << endl;

	return 0;
}