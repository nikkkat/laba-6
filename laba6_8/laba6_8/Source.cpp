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

bool write_left(string s, string t, int index)
{
	for (index; t.length() > 0 && index >= 0 && s[index] == t[0]; index--)
	{
		t = t.substr(1);
	}
	
	if (t.length() == 0) { return true; }
	else { return false; }
}

bool possible(string s, string t, int index)
{
	int a = s.length();

	for (int count = index; s[count] == t[count - index] && count < a; count++)
	{
		if (write_left(s, t.substr(count - index), count))
		{ return true; }
	}

	return false;
}

bool write_out(string s, string t)
{
	int a = s.length();
	for (int i = 0; i < a; i++)
	{
		if (possible(s, t, i))
		{ return true; }
	}
	return false;
}

int main()
{
	cout << "enter the number of inputs: ";
	int q = int_input();

	while (q > 0)
	{
		cout << endl << "enter string s: ";
		string s, t;
		getline(cin, s);
		cout << endl << "enter string t: ";
		getline(cin, t);

		cout << endl << "result:" << endl;
		if (write_out(s, t)) { cout << endl << "yes" << endl; }
		else { cout << endl << "no" << endl; }
		q--;
	}

	return 0;
}