#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const string fileName("inputs.txt");
const int len = 100;


bool isDot(char*& arr);
bool isSign(char*& arr);
bool isE(char*& arr);
bool isDigit(char*& arr);
bool isUInt(char*& arr, bool flag);
bool isOrdered(char*& arr);
bool isMantis(char*& arr);
bool isExpression(char*& arr);


int main()
{
	ifstream ifs;

	ifs.open(fileName);

	try
	{
		if (!ifs)
		{
			throw fileName + " file not found.";
		}

		while (!ifs.eof())
		{
			char* str;
			str = new char[len];
			ifs.getline(str, len, '\n');
			char* x = str;
			cout << str;
			if (isExpression(x))
			{
				cout << " True\n";
			}
			else
			{
				cout << " False\n";
			}
		}
	}

	catch (const string& error)
	{
		cerr << "\nError:" << error << "\n";
		exit(-1);
	}
	return 0;
}

bool isDot(char*& arr)
{
	if (*arr == '.')
	{
		arr++;
		return true;
	}
	return false;
}

bool isSign(char*& arr)
{
	if (*arr == '+' || *arr == '-')
	{
		arr++;
		return true;
	}
	return false;
}

bool isE(char*& arr)
{
	if (*arr == 'E')
	{
		arr++;
		return true;
	}
	return false;
}

bool isDigit(char*& arr)
{
	if (*arr >= '0' && *arr <= '9')
	{
		arr++;
		return true;
	}
	return false;
}

bool isUInt(char*& arr, bool flag)
{
	if (isDigit(arr))
	{
		if ((*arr == '.' && flag == true) || *arr == '\0' || *arr == 'E')
		{
			return true;
		}
		return isUInt(arr, flag);
	}
	return false;
}

bool isOrdered(char*& arr)
{
	if (isE(arr))
	{
		if (isSign(arr))
		{
			if (isUInt(arr, false))
			{
				return true;
			}
		}
	}
	return false;

}

bool isMantis(char*& arr)
{
	if (isUInt(arr, true) || *arr == '.')
	{
		if (isDot(arr))
		{
			if (isUInt(arr, false))
			{
				return true;
			}
		}
	}
	return false;
}

bool isExpression(char*& arr)
{
	if (isSign(arr))
	{
		if (isMantis(arr))
		{
			if (isOrdered(arr))
			{
				return true;
			}
		}
	}

	return false;
}

