#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

std::vector<int> signatures(std::list<std::pair<int, int>>& segments) {
    std::vector<int> ans;
    segments.sort([] (const auto& p1, const auto& p2) {
        return p1.second < p2.second;
    });
    while(!segments.empty()) {
        int rmin = segments.front().second;
        ans.push_back(rmin);
        auto it = segments.begin();
        while(it != segments.end()) {
            if ((*it).first <= rmin) {
                it = segments.erase(it);
                continue;
            }
            ++it;
        }
    }
    return ans;
}

int pointsAndSegments(std::vector<int>& points, int L) {
    std::sort(points.begin(), points.end());
    int idx = 0;
    int ans = 0;
    while (idx < points.size()) {
        int left = points[idx];
        ++ans;
        while(idx < points.size() && left + L >= points[idx]) {
            ++idx;
        }
    }
    return ans;
}

int minSumLengthSegments(std::vector<int>& points, int k) {
    if (points.size() <= k) return 0;
    int ans = 0;
    std::sort(points.begin(), points.end());
    std::vector<int> dist(points.size() - 1);
    for (int i = 0; i < points.size() - 1; ++i) {
        dist[i] = points[i + 1] - points[i];
        ans += dist[i];
    }
    std::sort(dist.begin(), dist.end());
    int idx = dist.size() - 1;
    for (int i = 0; i < k - 1; ++i) {
        ans -= dist[idx];
        --idx;
    }
    return ans;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }
    std::cout << minSumLengthSegments(points, k);
}