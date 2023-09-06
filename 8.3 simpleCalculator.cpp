#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n + 1, INT32_MAX - 1);
    dp[1] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
        if (i * 2 <= n) {
            dp[i * 2] = std::min(dp[i * 2], dp[i] + 1);
        }
        if (i * 3 <= n) {
            dp[i * 3] = std::min(dp[i * 3], dp[i] + 1);
        }
    }
    std::vector<int> ans(dp[n] + 1, 0);
    ans[dp[n]] = n;
    int idx = dp[n] - 1;
    while(idx >= 0) {
        if (n - 1 >= 1 && dp[n] == dp[n - 1] + 1) {
            ans[idx] = n - 1;
            idx--;
            n--;
        } else if (n % 2 == 0 && n / 2 >= 1 && dp[n] == dp[n / 2] + 1) {
            ans[idx] = n / 2;
            idx--;
            n /= 2;
        } else {
            ans[idx] = n / 3;
            idx--;
            n /= 3;
        }
    }
    std::cout << dp[dp.size() - 1] << "\n";
    for (int i = 0; i <= dp.back(); ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << ans[i];
    }
}