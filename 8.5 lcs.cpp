#include <iostream>
#include <vector>

template <typename T>
int lcs2(const T& first, const T& second) {
    std::vector<std::vector<int>> dp(first.size() + 1, std::vector<int>(second.size() + 1));
    for (int i = 1; i <= first.size(); ++i) {
        for (int j = 1; j <= second.size(); ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[first.size()][second.size()];
}

template <typename T>
int lcs3(const T& first, const T& second, const T& third) {
    std::vector<std::vector<std::vector<int>>> dp(first.size() + 1, std::vector<std::vector<int>>(second.size() + 1, std::vector<int>(third.size() + 1)));
    for (int i = 1; i <= first.size(); ++i) {
        for (int j = 1; j <= second.size(); ++j) {
            for (int k = 1; k <= third.size(); ++k) {
                dp[i][j][k] = std::max(dp[i - 1][j][k], std::max(dp[i][j - 1][k], dp[i][j][k - 1]));
                if (first[i - 1] == second[j - 1] && second[j - 1] == third[k - 1]) {
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
                }
            }
        }
    }
    return dp[first.size()][second.size()][third.size()];
}

void taskA() {
    int n1;
    std::cin >> n1;
    std::vector<int> v1(n1);
    for (int i = 0; i < n1; ++i) {
        std::cin >> v1[i];
    }
    int n2;
    std::cin >> n2;
    std::vector<int> v2(n2);
    for (int i = 0; i < n2; ++i) {
        std::cin >> v2[i];
    }
    std::cout << lcs2(v1, v2);
}

void taskB() {
    int n1;
    std::cin >> n1;
    std::vector<int> v1(n1);
    for (int i = 0; i < n1; ++i) {
        std::cin >> v1[i];
    }
    int n2;
    std::cin >> n2;
    std::vector<int> v2(n2);
    for (int i = 0; i < n2; ++i) {
        std::cin >> v2[i];
    }
    int n3;
    std::cin >> n3;
    std::vector<int> v3(n3);
    for (int i = 0; i < n3; ++i) {
        std::cin >> v3[i];
    }
    std::cout << lcs3(v1, v2, v3);
}

int main() {
    taskB();
}