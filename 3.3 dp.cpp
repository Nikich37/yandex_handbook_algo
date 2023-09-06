#include <iostream>
#include <vector>

void taskA() {
    int n, m;
    std::cin >> n >> m;
    if (n % 2 || m % 2) std::cout << "Win";
    else std::cout << "Loose";
}

void taskB() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i + 1 <= n) {
                dp[i + 1][j] = std::max((int)!dp[i][j], dp[i + 1][j]);
            } 
            if (j + 1 <= m) {
                dp[i][j + 1] = std::max((int)!dp[i][j], dp[i][j + 1]);
            }
            if (i + 2 <= n) {
                dp[i + 2][j] = std::max((int)!dp[i][j], dp[i + 2][j]);
            }
            if (j + 2 <= n) {
                dp[i][j + 2] = std::max((int)!dp[i][j], dp[i][j + 2]);
            }
            if (i + 2 <= n && j + 1 <= m) {
                dp[i + 2][j + 1] = std::max((int)!dp[i][j], dp[i + 2][j + 1]);
            }
            if (i + 1 <= n && j + 2 <= m) {
                dp[i + 1][j + 2] = std::max((int)!dp[i][j], dp[i + 1][j + 2]);
            }
        }
    }
    std::cout << (dp[n][m] ? "Win" : "Loose");
}

int main() {
    taskB();
}