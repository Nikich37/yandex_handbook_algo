#include <cmath>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int k = (-1 + sqrt(1 + 8 * n)) / 2;
    std::cout << k << "\n";
    int price = 1;
    for (int i = 0; i < k; ++i) {
        std::cout << price++ << " ";
    }
}