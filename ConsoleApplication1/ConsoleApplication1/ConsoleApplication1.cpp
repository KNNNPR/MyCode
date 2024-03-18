
#include <iostream>
#include <cmath>
using namespace std;
double z(double s, double n, double p) {
	double r = p / 100;
	return (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}
int main() 
{
	setlocale(0, "");
	double s, n, m, p = 50;
	cout << "Ссуда: ";
	cin >> s;
	while (s < 0) 
	{
		cout << "Введите ссуду еще раз! ";
		cin >> s;
	}
	cout << "Количество лет: ";
	cin >> n;
	while (n < 0) 
	{
		cout << "Введите  кол-во лет еще раз ";
		cin >> n;
	}
	cout << "Месячная выплата: ";
	cin >> m;
	while (m < 0) 
	{
		cout << "Введите  величину месячной выплаты еще раз ";
		cin >> m;
	}
	while  (1>0)
	{
		if (m - 0.01 <= z(s, n, p) && z(s, n, p) <= m + 0.01) {
			break;
		}
		else 
		{
			if (z(s, n, p) > m) 
			{
				p = p * 0.5;
			}
			else {
				p = p * 1.5;
			}
		}
	}
	cout << "Ссуда под " << p << " процентов.";
	return 0;
}


