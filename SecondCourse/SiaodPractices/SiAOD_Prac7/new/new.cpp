#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int findLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maxLen = 1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > maxLen) {
            maxLen = dp[i];
        }
    }
    return maxLen;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<int> sequence = { 5,10,3,12,5,50,6};

    int result = findLIS(sequence);

    cout << "Длина самой длинной строго возрастающей подпоследовательности: " << result << endl;

}

