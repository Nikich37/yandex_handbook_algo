#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
        if (i + 3 <= n) {
            dp[i + 3] = std::min(dp[i + 3], dp[i] + 1);
        }
        if (i + 4 <= n) {
            dp[i + 4] = std::min(dp[i + 4], dp[i] + 1);
        }
    }
    std::cout << dp[n];
}