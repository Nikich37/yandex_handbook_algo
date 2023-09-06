#include <iostream>

long long gcd(long long a, long long b) {
    while (a != 0 && b != 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return std::max(a, b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// наибольшее число шагов алгоритма Евклида
// два последовательных числа Фибонначи последних перед n
std::pair<long long, long long> pair_ab(long long n) {
    int prev = 0;
    int next = 1;
    while (prev + next <= n) {
        int temp = next;
        next = prev + next;
        prev = temp;
    }
    return {prev, next};
}

int main() {
    std::pair<int, int> ans = pair_ab(10000);
    std::cout << ans.first << " " << ans.second;
}