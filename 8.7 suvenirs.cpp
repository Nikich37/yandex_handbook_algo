#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> items(n);
    int V = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> items[i];
        V += items[i];
    }
    if (V % 3 != 0) {
        std::cout << 0;
        return 0;
    }
    V /= 3;
    std::vector<std::vector<std::vector<bool>>> dp(n + 1, std::vector<std::vector<bool>>(V + 1, std::vector<bool>(V + 1, false)));
    dp[0][0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int s1 = 0; s1 <= V; ++s1) {
            for (int s2 = 0; s2 <= V; ++s2) {
                dp[i][s1][s2] = dp[i - 1][s1][s2];
                if (s1 >= items[i - 1]) {
                    dp[i][s1][s2] = dp[i][s1][s2] || dp[i - 1][s1 - items[i - 1]][s2];
                }
                if (s2 >= items[i - 1]) {
                    dp[i][s1][s2] = dp[i][s1][s2] || dp[i - 1][s1][s2 - items[i - 1]];
                }
            }
        }
    }
    std::cout << dp[n][V][V];
}