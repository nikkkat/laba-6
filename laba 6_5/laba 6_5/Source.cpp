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

int foo(string s1, string s2, int l, int m)
{
	int k;
	
	if (s1.length() + s2.length() < l)
	{
		if (s1 == s2) { k = pow(26, l - (s1.length() + s2.length())); }
		else { k = pow(26, l - (s1.length() + s2.length())) * 2; }
		return k % m;
	}

	else if (s1.length() + s2.length() == l)
	{
		if (s1 == s2) { return 1 % m; }
		else { return 2 % m; }
	}

	else if (s1.length() + s2.length() - l <= s1.length() || s1.length() + s2.length() - l <= s2.length())
	{
		string a1, a2, a3, a4;
		int count;
		count = s1.length() + s2.length() - l;
		
		for (int i = s1.length() - count; i < s1.length(); ++i)
		{
			a1 += s1[i];
		}
		for (int i = 0; i < count; ++i)
		{
			a2 += s2[i];
		}
		for (int i = s2.length() - count; i < s2.length(); ++i)
		{
			a3 += s2[i];
		}
		for (int i = 0; i < count; ++i)
		{
			a4 += s1[i];
		}
		
		if (s1 == s2) { return 1 % m; }
		else if (a1 == a2 && a3 == a4)
		{
			if (a4 == a1 || a2 == a3) { return 1 % m; }
			else { return 2 % m; }
		}
		else if (a1 == a2 || a3 == a4) { return 1 % m; }
		else { return 0; }
	}

	else { return 0; }
	 
}

int main()
{
	int t;
	cout << "enter the number of inputs t: ";
	t = int_input();
	
	while (t > 0)
	{
		int l, m;
		cout << endl << "enter l: ";
		l = int_input();
		cout << endl << "enter m: ";
		m = int_input();
		cout << endl << "enter line s1: ";
		string s1, s2;
		getline(cin, s1);
		cout << endl << "enter line s2: ";
		getline(cin, s2);

		int i = 1;
		cout << endl << "result ¹ " << i << ": " << foo(s1, s2, l, m) << endl;
		i++;
		t--;
	}

	return 0;
}