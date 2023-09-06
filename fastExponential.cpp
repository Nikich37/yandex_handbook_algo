#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int ans = 1;
    int current = n;
    while (m) {
        if (m % 2 == 0) {
            current *= current;
        } else {
            ans *= current;
        }
        m /= 2;
    }
    std::cout << ans;
}