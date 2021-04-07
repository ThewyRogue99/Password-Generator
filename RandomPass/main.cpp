#include <iostream>

using namespace std;

char* createPass(int length)
{
	srand(time(NULL));
	char* res = new char[length];
	for (int i = 0; i < length; i++)
	{
		if (i != length - 1)
		{
			int num = (rand() % (127 - 32)) + 32;
			res[i] = num;
		}
		else
			res[i] = '\0';
	}
	return res;
}

int main()
{
	int length = 0;
	while (true)
	{
		cout << "Please enter the length of the password: ";
		cin >> length;
		if (length < 1)
		{
			cout << "Password length cannot be smaller than 1" << endl;
			continue;
		}
		cout << "New password is: " << createPass(length + 1) << endl;
		while (true)
		{
			char proceed;
			cout << "Proceed? [y/n] ";
			cin >> proceed;
			if (tolower(proceed) == 'n')
				return 0;
			else if (tolower(proceed) == 'y')
				break;
			else
			{
				cout << "Undefined option" << endl;
				continue;
			}
		}
	}
	return 0;
}