#include <iostream>
#include <bitset>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include<random>
using namespace std;

int Random() //генератор рандомного числа
{
	random_device rand_dev;
	mt19937 gen(rand_dev());
	uniform_int_distribution<int> random(100000, 999999);
	return random(gen);
}


void Task_1() {

	int bytes = (pow(10, 7) + 7) / 8;
	vector<unsigned char> nums(bytes);
	ofstream f2("Ввод.txt");

	for (int i = 0; i < 1000000; i++) {
		f2 << Random() << endl;
	}
	f2.close();
	ifstream f("Ввод.txt");
	ofstream f1("Вывод.txt");
	string line;


	cout << "Файлы открыты." << endl;
	int bitId, byteInd, setbit;
	while (getline(f, line)) {
		bitId = stoi(line);
		byteInd = bitId / 8; // Индекс байта в котором находится бит
		setbit = bitId % 8; // Смещение внутри байта для доступа к биту
		nums[byteInd] |= (1 << setbit); // Устанавливаем бит в байте
	}

	f.close();
	cout << "Биты установлены." << endl;
	auto t0 = chrono::steady_clock::now();
	for (int byteInd = 0; byteInd < bytes; byteInd++) { // запись в файл отсортированных чисел
		unsigned char byte = nums[byteInd];
		for (int bitId = 0; bitId < 8; bitId++) {
			bool isBitSet = (byte & (1 << bitId));
			if (isBitSet == 1)
				f1 << (byteInd * 8 + bitId) << endl;
		}
	}
	cout << "Файл записан." << endl;
	f1.close();
	auto t1 = chrono::steady_clock::now();
	auto fint = chrono::duration_cast<chrono::microseconds>(t1 - t0);
	cout << "Время на поиск: " << fint.count() / 1000000.0 << endl << "Пямять в МБ:  " << nums.capacity() / (pow(2, 20));


}

int main()
{
	setlocale(LC_ALL, "Russian");
	Task_1();
}
