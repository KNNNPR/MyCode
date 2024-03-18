#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


void EnterDynamic(int* a, int L)
{
	for (int i = 0; i < L; i++)
	{
		cin >> a[i];
	}
}
void ShowDynamic(int* a, int L)
{
	for (int i = 0; i < L; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void ShowVector(vector <int> a, int l)
{
	for (int i = 0; i < l; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void EnterVector(vector <int> a, int L)
{
	for (int i = 0; i < L; i++)
	{
		cin >> a[i];
	}
}
bool Palindrome(string x)
{
	if (x.length() >= 2)
	{
		if (x[0] == '-')
		{
			x = x + '-';
		}
		for (int i = 0; i < x.length() / 2; i++)
		{
			if (x[i] != x[x.length() - i - 1])
			{
				return (false);
			}
		}
		return (true);
	}
	else
	{
		return (false);
	}
}
void ShowPalindromes(int* a, int l)
{
	cout << "There are some Palindromes indexes...";
	for (int i = 0; i < l; i++)
	{
		if (Palindrome(to_string(a[i])))
		{
			cout << i << ' ';
		}
	}
	cout << endl;
}
int FindPalindrome(int* a, int l)
{
	for (int i = 0; i < l; i++)
	{
		if (Palindrome(to_string(a[i])))
		{
			return (i);
		}
	}
	return (-1);
}
int FindPalindromesVector(vector <int> a, int l)
{
	for (int i = 0; i < l; i++)
	{
		if (Palindrome(to_string(a[i])))
		{
			return (i);
		}
	}
	return (-1);
}
void ShowPalindromeVector(vector <int> a, int l)
{
	cout << "There are some Palindromes indexes...";
	for (int i = 0; i < l; i++)
	{
		if (Palindrome(to_string(a[i])))
		{
			cout << i << ' ';
		}
	}
	cout << endl;
}
void ArrayDeletePrePalindrome(int* a, int l, int Index)
{
	for (int i = Index; i < l; i++)
	{
		a[i - Index] = a[i];
	}
}
vector <int> ArrayDeletePrePalindromeVector(vector <int> a, int l, int Index)
{
	for (int i = Index; i < l; i++)
	{
		a[i - Index] = a[i];
	}
	return a;
}
void ArrayAppendPostPalindrome(int* a, int l, int Index)
{
	int App;
	cin >> App;
	for (int i = l + 1; i > Index; i--)
	{
		a[i] = a[i - 1];
	}
	a[Index + 1] = App;
}
vector <int> ArrayAppendPostPalindromeVector(vector <int> a, int l, int Index)
{
	int App;
	cin >> App;
	for (int i = l - 1; i > Index; i--)
	{
		a[i] = a[i - 1];
	}
	a[Index + 1] = App;
	return a;
}

int main()
{
	int ChoiceArray;
	cout << "Choose type of Array you want to work with" << endl;
	cout << "1 - Dynamic, 2 - Static, 3 - Vector" << endl;
	cin >> ChoiceArray;

	if (ChoiceArray == 1)
	{
		int ChoiceOperation;
		int Length;
		cout << "Enter length of Array" << endl;
		cin >> Length;
		int* a = (int*)malloc(sizeof(int) * Length);
		EnterDynamic(a, Length);
		do
		{
			cout << "Enter 1, 2 or 3 to choose operation" << endl;
			cout << "1 - Show indexes of Palindromes, 2 - To delete elements previous to palindrome element, 3 - To paste new element right after Palindrome" << endl;
			cin >> ChoiceOperation;
			switch (ChoiceOperation)
			{
			case 1:
			{
				ShowPalindromes(a, Length);
			}
			break;
			case 2:
			{
				int PalindromeIndex = FindPalindrome(a, Length);
				if (PalindromeIndex != -1)
				{
					ArrayDeletePrePalindrome(a, Length, PalindromeIndex);
					Length -= PalindromeIndex;
					ShowDynamic(a, Length);
					a = (int*)realloc(a, sizeof(int) * Length);
				}
				break;
			}
			case 3:
			{
				int PalindromeIndex = FindPalindrome(a, Length);
				if (PalindromeIndex != -1)
				{
					Length += 1;
					a = (int*)realloc(a, sizeof(int) * Length);
					ArrayAppendPostPalindrome(a, Length, PalindromeIndex);
					ShowDynamic(a, Length);
				}
			}
			break;
			}
		} while (ChoiceOperation == 1 || ChoiceOperation == 2 || ChoiceOperation == 3);
	}
	else if (ChoiceArray == 2)
	{
		int ChoiceOperation;
		int Length;
		cout << "Enter length of Array" << endl;
		cin >> Length;
		int a[100];
		EnterDynamic(a, Length);
		do
		{
			cout << "Enter 1, 2 or 3 to chooce operation" << endl;
			cout << "1 - Show indexes of Palindromes, 2 - To delete elements previous to palindrome element, 3 - To paste new element right after Palindrome" << endl;
				cin >> ChoiceOperation;
			switch (ChoiceOperation)
			{
			case 1:
			{
				ShowPalindromes(a, Length);
			}
			break;
			case 2:
			{
				int PalindromeIndex = FindPalindrome(a, Length);
				if (PalindromeIndex != -1)
				{
					ArrayDeletePrePalindrome(a, Length, PalindromeIndex);
					Length -= PalindromeIndex;
					ShowDynamic(a, Length);
				}
			}
			break;
			case 3:
			{
				int PalindromeIndex = FindPalindrome(a, Length);
				if (PalindromeIndex != -1)
				{
					Length += 1;
					ArrayAppendPostPalindrome(a, Length, PalindromeIndex);
					ShowDynamic(a, Length);
				}
			}
			break;
			}
		} while (ChoiceOperation == 1 || ChoiceOperation == 2 || ChoiceOperation == 3);
	}
	else if (ChoiceArray == 3)
	{
		int ChoiceOperation;
		int Length;
		cout << "Enter length" << endl;
		cin >> Length;
		vector <int> a(Length);
		for (int i = 0; i < Length; i++)
		{
			cin >> a[i];
		}
		do
		{
			cout << "Enter 1, 2 or 3 to chooce operation" << endl;
			cout << "1 - Show indexes of Palindromes, 2 - To delete elements previous to palindrome element, 3 - To paste new element right after Palindrome" << endl;
			cin >> ChoiceOperation;
			switch (ChoiceOperation)
			{
			case 1:
			{
				ShowPalindromeVector(a, Length);
			}
			break;
			case 2:
			{
				int PalindromeIndex = FindPalindromesVector(a, Length);
				if (PalindromeIndex != -1)
				{
					a = ArrayDeletePrePalindromeVector(a, Length, PalindromeIndex);
					Length -= PalindromeIndex;
					a.resize(Length);
				}
				ShowVector(a, Length);
			}
			break;
			case 3:
			{
				int PalindromeIndex = FindPalindromesVector(a, Length);
				if (PalindromeIndex != -1)
				{
					Length += 1;
					a.resize(Length);
					a = ArrayAppendPostPalindromeVector(a, Length, PalindromeIndex);
					ShowVector(a, Length);
				}
			}
			break;
			}
		} while (ChoiceOperation == 1 || ChoiceOperation == 2 || ChoiceOperation == 3);
	}
}