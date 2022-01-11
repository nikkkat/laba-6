#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "enter text:" << endl;
	string str;
	getline(cin, str);
	int k = str.size();

	for (int i = 0; i < k; i++)
	{
		if (str[i] == 'c' && str[i + 1] == 'e' || str[i] == 'c' && str[i + 1] == 'i' || str[i] == 'c' && str[i + 1] == 'y')
		{
			str[i] = 's';
		}
		else if (str[i] == 'C' && str[i + 1] == 'e' || str[i] == 'C' && str[i + 1] == 'i' || str[i] == 'C' && str[i + 1] == 'y')
		{
			str[i] = 'S';
		}
		else if (str[i] == 'c') { str[i] = 'k'; }
		else if (str[i] == 'C') { str[i] = 'K'; }

		if (str[i] == 'q' && str[i + 1] == 'u') { str[i] = 'k'; str[i + 1] = 'v'; }
		else if (str[i] == 'Q' && str[i + 1] == 'u') { str[i] = 'K'; str[i + 1] = 'v'; }
		else if (str[i] == 'q') { str[i] = 'k'; }
		else if (str[i] == 'Q') { str[i] = 'K'; }

		if (str[i] == 'w') { str[i] = 'v'; }
		else if (str[i] == 'W') { str[i] = 'v'; }

		if (str[i] == 'x')
		{
			for (int j = k; j > i + 1; j--)
			{
				str[j] = str[j - 1];
			}
			str[i] = 'k';
			str[i + 1] = 's';
			
		}
		else if (str[i] == 'X')
		{
			for (int j = k; j > i + 1; j--)
			{
				str[j] = str[j - 1];
			}
			str[i] = 'K';
			str[i + 1] = 's';
			
		}

		if (str[i] == 'p' && str[i + 1] == 'h')
		{
			str[i] = 'f';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}
		else if (str[i] == 'P' && str[i + 1] == 'h')
		{
			str[i] = 'F';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}

		if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u')
		{
			str[i] = 'u';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 2];
			}
			k -= 2;
		}
		else if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u')
		{
			str[i] = 'U';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 2];
			}
			k -= 2;
		}

		if (str[i] == 'o' && str[i + 1] == 'o')
		{
			str[i] = 'u';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}
		else if (str[i] == 'O' && str[i + 1] == 'o')
		{
			str[i] = 'U';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}

		if (str[i] == 'e' && str[i + 1] == 'e')
		{
			str[i] = 'i';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}
		else if (str[i] == 'E' && str[i + 1] == 'e')
		{
			str[i] = 'I';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}

		if (str[i] == 't' && str[i + 1] == 'h')
		{
			str[i] = 'z';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}
		else if (str[i] == 'T' && str[i + 1] == 'h')
		{
			str[i] = 'Z';
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}
	}

	for (int i = 0; i < k; i++)
	{
		if (str[i] == str[i + 1])
		{
			for (int j = i + 1; j < k; j++)
			{
				str[j] = str[j + 1];
			}
			k--;
		}
	}

	cout << endl << endl << str << endl << endl;

	return 0;
}