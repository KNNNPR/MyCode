#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif
#include <iostream>
#include <string>

using namespace std;

void DeleteNumsChar(char* Sentence)
{
	int i = 1;
	int length = strlen(Sentence);
	while (i < length)
	{
		if (((int)Sentence[i] <= 57) && ((int)Sentence[i] >= 48))
		{
			for (int j = i; j < length; j++)
			{
				Sentence[j] = Sentence[j + 1];
			}
		}
		else
		{
			i++;
		}
	}
}
void ShiftNumsChar(char* Sentence)
{
	int i = 1;
	int length = strlen(Sentence);
	for (int i = 1; i < length; i++)
	{
		for (int j = 1; j < length - i; j++)
		{
			if ((((int)Sentence[j] <= 57) && ((int)Sentence[j] >= 48)) && not(((int)Sentence[j + 1] <= 57) && ((int)Sentence[j + 1] >= 48)))
			{
				swap(Sentence[j], Sentence[j + 1]);
			}
		}
	}
	for (int i = 1; i < length; i++)
	{
		if (((int)Sentence[i] <= 57) && ((int)Sentence[i] >= 48))
		{
			swap(Sentence[i], Sentence[length - 1]);
			break;
		}
	}
}
string DeleteNumsString(string Sentence)
{
	int i = 1;
	int length = Sentence.length();
	while (i < length)
	{
		if (((int)Sentence[i] <= 57) && ((int)Sentence[i] >= 48))
		{
			for (int j = i; j < length; j++)
			{
				Sentence[j] = Sentence[j + 1];
			}
		}
		else
		{
			i++;
		}
	}
	return (Sentence);
}
string ShiftNumsString(string Sentence)
{
	for (int i = 1; i < Sentence.length() - 1; i++)
	{
		for (int j = 1; j < Sentence.length() - 1; j++)
		{
			if ((((int)Sentence[j] <= 57) && ((int)Sentence[j] >= 48)) && not(((int)Sentence[j + 1] <= 57) && ((int)Sentence[j + 1] >= 48)))
			{
				swap(Sentence[j], Sentence[j + 1]);
			}
		}
	}
	for (int j = 1; j < Sentence.length(); j++)
	{
		if ((((int)Sentence[j] <= 57) && ((int)Sentence[j] >= 48)))
		{
			swap(Sentence[j], Sentence[Sentence.length() - 1]);
			break;

		}
	}
	return (Sentence);
}
int main()
{
	int Choise;
	do
	{
		do
		{
			cout << "Choose type of Sentense: 1 - Dynamic char array, 2 - String type" << endl;
			cin >> Choise;
		} while (Choise != 1 && Choise != 2);
		switch (Choise)
		{
		case 1:
		{
			char* Sentence = (char*)malloc(sizeof(char) * 256);
			char Control;
			cout << "Enter Sentence" << endl;
			cin.getline(Sentence, 256, '.');
			cout << "Y or N ?" << endl;
			cin >> Control;
			if (Control == 'Y')
			{
				DeleteNumsChar(Sentence);
				cout << Sentence << endl;
			}
			else
			{
				ShiftNumsChar(Sentence);
				cout << Sentence << endl;
			}
		}
		break;
		case 2:
		{
			char Control;
			string Sentence;
			cout << "Enter Sentence" << endl;
			getline(cin, Sentence, '.');
			cout << "Y or N ?" << endl;
			cin >> Control;
			if (Control == 'Y')
			{
				cout << DeleteNumsString(Sentence) << endl;
			}
			else if (Control == 'N')
			{
				cout << ShiftNumsString(Sentence) << endl;
			}
		}
		}
	} while (Choise == 1 || Choise == 2);
}
