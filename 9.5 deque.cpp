#include <queue>
#include <iostream>

void taskA() {
    int q;
    std::cin >> q;
    std::queue<int> queue;
    for (int i = 0; i < q; ++i) {
        int request;
        std::cin >> request;
        if (request == 1) {
            int x;
            std::cin >> x;
            queue.push(x);
        } else {
            queue.pop();
        }
        std::cout << (queue.empty() ? -1 : queue.front()) << "\n"; 
    }
}