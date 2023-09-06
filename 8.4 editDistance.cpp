#include <iostream>
#include <vector>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1));
    for (int i = 0; i <= s1.size(); ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= s2.size(); ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            int d1 = dp[i - 1][j] + 1;
            int d2 = dp[i][j - 1] + 1;
            int d3;
            if (s1[i - 1] == s2[j - 1]) {
                d3 = dp[i - 1][j - 1];
            } else {
                d3 = dp[i - 1][j - 1] + 1;
            }
            dp[i][j] = std::min(d1, std::min(d2, d3));
        }
    }
    std::cout << dp[s1.size()][s2.size()];
}