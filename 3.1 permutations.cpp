#include <iostream>


long long fact(int num) {
    long long ans = 1;
    for (int i = 2; i <= num; ++i) {
        ans *= i;
    }
    return ans;
}

// число перестановок - факториал
void taskA() {
    int n;
    std::cin >> n;
    long long ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
    }
    std::cout << ans;
}

// число сочетаний - n!/(n - k)! / k!
void taskB() {
    int n, k;
    std::cin >> n >> k;
    std::cout << fact(n) / (fact(n - k) * fact(k));
}

// число сочетаний с повторениями - (n + k - 1)! / (n - 1)! / k!
void taskC() {
    int n, k;
    std::cin >> n >> k;
    std::cout << fact(n + k - 1) / (fact(n - 1) * fact(k)) << "\n";
}

int main() {
    taskC();
}