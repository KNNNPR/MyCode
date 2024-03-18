#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Глобальная переменная для подсчета переборов
int countPermutations = 0;

// Функция для вычисления количества скалярных умножений в данной расстановке скобок
int countScalarMultiplications(const vector<int>& dimensions, const vector<int>& parentheses) {
    int n = dimensions.size() - 1;
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    return m[0][n - 1];
}

// Функция для генерации всех возможных расстановок скобок
void generateParenthesesCombinations(vector<int>& parentheses, int open, int close, int pos) {
    if (open == 0 && close == 0) {
        // Вычисляем количество скалярных умножений для текущей расстановки
        int scalarMultiplications = countScalarMultiplications(parentheses, parentheses);

        // Выводим текущую расстановку и количество скалярных умножений
        for (int i = 0; i < parentheses.size(); i++) {
            cout << (parentheses[i] == 0 ? "(" : ")");
        }
        cout << endl;

        countPermutations++; // Увеличиваем счетчик переборов

        return;
    }

    if (open > 0) {
        parentheses[pos] = 0; // Открывающаяся скобка
        generateParenthesesCombinations(parentheses, open - 1, close, pos + 1);
    }

    if (close > open) {
        parentheses[pos] = 1; // Закрывающаяся скобка
        generateParenthesesCombinations(parentheses, open, close - 1, pos + 1);
    }
}

// Функция для решения задачи методом грубой силы
void bruteForceMatrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<int> parentheses(2 * n - 2, 0); // Вектор для хранения расстановки скобок

    cout << "Все возможные расстановки скобок:" << endl;
    generateParenthesesCombinations(parentheses, n - 1, n - 1, 0);

    cout << "Количество переборов: " << countPermutations << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> dimensions = { 5, 10, 3, 12, 5, 50, 6 };
    bruteForceMatrixChainOrder(dimensions);

    return 0;
}