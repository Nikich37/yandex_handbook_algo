#include <iostream>
#include <cmath>

void hanoi(int n, int start, int end) {
    if (n == 1) {
        std::cout << start << " " << end << "\n";
        return;
    }
    int temp = 6 - end - start;
    hanoi(n - 1, start, temp);
    std::cout << start << " " << end << "\n";
    hanoi(n - 1, temp, end);
}
void taskA() {
    int n;
    std::cin >> n;
    std::cout << std::pow(2, n) - 1 << "\n";
    hanoi(n, 1, 3);
}

int ans = 0;
void hanoi(int n, int start, int temp1, int temp2, int end) {
    if (n == 1) {
        ans++;
    }

}

int main() {
    taskA();    
}