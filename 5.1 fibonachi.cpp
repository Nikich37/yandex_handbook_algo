#include <iostream>

#include <iostream>



long long get_fibonachi(int n) {
    if (n < 2) return n;
    else {
        int prev = 1;
        int prev_prev = 0;
        int ans;
        for (int i = 2; i <= n; ++i) {
            ans = prev + prev_prev;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
}

int last_digit_fibonachi(int n) {
    if (n < 2) return n;
    else {
        int prev = 1;
        int prev_prev = 0;
        int ans;
        for (int i = 2; i <= n; ++i) {
            ans = (prev + prev_prev) % 10;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
}

int large_fibonachi(long long n, int m) {
    // find period pizano
    int current = 0;
    int next = 1;
    int period = 0;
    while (true) {
        int temp = next;
        next = (current + next) % m;
        current = temp;
        period++;
        if (current == 0 && next == 1) {
            break;
        }
    }
    n %= period;
    current = 0;
    next = 1;
    for (int i = 0; i < n; ++i) {
        int temp = next;
        next = (current + next) % m;
        current = temp;
    }
    return current;
} 

int last_digit_sum_fibonachi(long long n) {
    // find period
    int cur = 0;
    int next = 1;
    int p = 0;
    int sumP = 0;
    while (true) {
        int temp = next;
        next = (cur + next) % 10;
        cur = temp;
        p++;
        sumP += cur;
        if (cur == 0 && next == 1) break;
    }
    int ans = ((n / p) % 10) * (sumP % 10);
    int remainder = n % p;
    cur = 0;
    next = 1;
    for (int i = 0; i < remainder; ++i) {
        int temp = next;
        next = (cur + next) % 10;
        cur = temp;
        ans = (ans + cur) % 10;
    }
    return ans;
}

int main() {
    // частичная сумма фибоначчи
    long long m, n;
    std::cin >> m >> n;
    int ans = last_digit_sum_fibonachi(n) - last_digit_sum_fibonachi(m - 1);
    if (ans < 0) ans += 10;
    std::cout << ans << " " << last_digit_sum_fibonachi(n) << " " << last_digit_sum_fibonachi(m - 1);
}