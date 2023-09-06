#include <map>
#include <iostream>

void taskA() {
    int q;
    std::cin >> q;
    std::map<int, int> m;
    for (int i = 0; i < q; ++i) {
        int request;
        std::cin >> request;
        int x;
        std::cin >> x;
        if (request == 1) {
            int y;
            std::cin >> y;
            m[x] = y;
        } else {
            int ans = m.count(x) ? m[x] : -1;
            std::cout << ans << "\n";
        }
    }
}

int main() {
    taskA();
}