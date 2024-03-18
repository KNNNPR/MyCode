#include <iostream>
#include <vector>

using namespace std;

// Глобальная переменная для подсчета переборов
int countPermutations = 0;

// Функция для оптимальной расстановки скобок и вывода размеров матриц
void printOptimalParentheses(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1; // Матрица размера dimensions[i] x dimensions[i+1]
    }
    else {
        cout << "(";
        printOptimalParentheses(s, i, s[i][j]);
        cout << " * ";
        printOptimalParentheses(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// Функция для оптимальной расстановки скобок, нахождения минимального количества скалярных умножений и подсчета переборов
int greedyMatrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Количество матриц
    vector<vector<int>> m(n, vector<int>(n, 0)); // Матрица для хранения результатов
    vector<vector<int>> s(n, vector<int>(n, 0)); // Матрица для хранения оптимальных точек разреза

    // Заполняем матрицы m и s
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
                countPermutations++; // Увеличиваем счетчик переборов
            }
        }
    }

    // Выводим оптимальную расстановку скобок
    cout << "Оптимальная расстановка скобок с размерами матриц: ";
    printOptimalParentheses(s, 0, n - 1);
    cout << endl;

    return m[0][n - 1]; // Возвращаем минимальное количество скалярных умножений
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> dimensions = { 5, 10, 3, 12, 5, 50, 6 };
    int minScalarMultiplications = greedyMatrixChainOrder(dimensions);

    // Выводим результат и количество переборов
    cout << "Минимальное количество скалярных умножений (жадный алгоритм): " << minScalarMultiplications << endl;
    cout << "Количество переборов: " << countPermutations << endl;

    return 0;
}