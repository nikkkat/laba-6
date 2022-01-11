#include <iostream>
#include <string>
using namespace std;

bool palindrom(string s)
{
	bool pal = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == s[s.length() - i - 1]) 
		{
			pal = pal && true; 
		}
		else { pal = false; }
	}

	return pal;
}

int main()
{
	string s;
	cout << "enter line: ";
	getline(cin, s);

	int max = 0;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i + 1; j <= s.length(); j++)
		{
			string sub = s.substr(i, j - i);
			if (palindrom(sub) == false)
			{
				if (sub.length() > max) 
				{ max = sub.length(); }
			}
		}
	}

	cout <<endl << "result: " << endl;
	if (max == 0) 
	{ cout << "-1" << endl; }
	else 
	{ cout << max << endl; }

	return 0;
}