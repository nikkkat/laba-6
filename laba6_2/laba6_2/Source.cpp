#include <iostream>
#include <string>
using namespace std;

int int_input()
{
	int k = 0;
	cin >> k;
	while (k < 1 || cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "enter correct input: ";
		cin >> k;
	}

	return k;
}

bool prov(char a) 
{
	if (a != 'a' && a != 'A' && a != 'e' && a != 'E' &&
		a != 'i' && a != 'I' && a != 'y' && a != 'Y' &&
		a != 'o' && a != 'O' && a != 'u' && a != 'U') 
	{
		return true;
	}
	else { return false; }
}

int main()
{
	char str[100];
	cout << "enter string: ";
	cin.getline(str, 100);
	int k = strlen(str);
	
	cout << "the length of words to delete: ";
	int len = int_input();

	int count = 0;

	if (str[len] == ' ' && prov(str[0])) {
		count = len;
	}
	if (str[k - len - 1] == ' ' && prov(str[k - len])) {
		k -= len;
	}

	cout << endl << "fixed text: ";
	for (; count < k; count++) {

		if (str[count] == ' ' && str[count + 1 + len] == ' ' && prov(str[count + 1])) {
			count += len;
		}
		else {
			cout << *(str + count);
		}
	}
	cout << endl;

	return 0;
}



