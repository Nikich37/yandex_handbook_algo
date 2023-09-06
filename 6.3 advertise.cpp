#include <iostream>
#include <vector>
#include <algorithm>

int max_revenue(std::vector<int>& clicks, std::vector<int>& price) {
    std::sort(clicks.begin(), clicks.end());
    std::sort(price.begin(), price.end());
    int ans = 0;
    int n = clicks.size() - 1;
    while(n >= 0) {
        int max_price = price[n];
        int max_click = clicks[n];
        ans += max_click * max_price;
        --n;
    }
    return ans;
}

long long billboards(int n, int w, std::vector<std::pair<int, int>> ads) {
    long long ans = 0;
    std::sort(ads.begin(), ads.end());
    int time = n * w;
    int k = ads.size() - 1;
    while (time && k >= 0) {
        int cur_price = ads[k].first;
        int cur_time = ads[k].second;
        cur_time = std::min(cur_time, time);
        ans += cur_price * cur_time;
        time -= cur_time;
        k--;
    }
    return ans;
}

int main() {
    int n, k, w;
    std::cin >> n >> k >> w;
    std::vector<std::pair<int, int>> ads(k);
    for (int i = 0; i < k; ++i) {
        int price, time;
        std::cin >> price >> time;
        ads[i] = {price, time};
    }
    std::cout << billboards(n, w, ads);

}