#include <list>
#include <iostream>

void taskA() {
    int n;
    std::cin >> n;
    std::list<std::pair<int, int>> intervals;
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        intervals.push_back({l, r});
    }
    intervals.sort([](const auto& p1, const auto& p2) {
        return p1.second < p2.second;
    });
    int ans = 0;
    while(!intervals.empty()) {
        ans++;
        int r = intervals.front().second;
        auto it = intervals.begin();
        while (it != intervals.end()) {
            if ((*it).first <= r) {
                it = intervals.erase(it);
            } else {
                it++;
            }
        }
    }
    std::cout << ans;
}

int main() {
    taskA();
}