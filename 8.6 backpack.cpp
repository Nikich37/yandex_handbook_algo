#include <iostream>
#include <vector>


int main() {
    int n, W;
    std::cin >> W >> n;
    std::vector<int> w(n);
    std::vector<std::vector<bool>> pack(W + 1, std::vector<bool>(n + 1, false));
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    pack[0][0] = true;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int weight = 0; weight <= W; weight++) {
            if (w[i - 1] > weight) {
                pack[weight][i] = pack[weight][i - 1];
            } else {
                pack[weight][i] = pack[weight][i - 1] || pack[weight - w[i - 1]][i - 1];
            }
            if (pack[weight][i] == true) {
                ans = std::max(ans, weight);
            }
        }
    }
    std::cout << ans;
    
}