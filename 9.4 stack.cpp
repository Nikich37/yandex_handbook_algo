#include <stack>
#include <set>
#include <iostream>
#include <vector>

void taskA() {
    int q;
    std::cin >> q;
    std::stack<int> st;
    for (int i = 0; i < q; ++i) {
        int request;
        std::cin >> request;
        if (request == 1) {
            int x;
            std::cin >> x;
            st.push(x);
        } else {
            st.pop();
        }
        int top = st.empty() ? -1 : st.top();
        std::cout << top << "\n";
    }
}

void taskB() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    std::stack<std::pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        int tower;
        std::cin >> tower;
        while (!st.empty() && st.top().first < tower) {
            st.pop();
        }
        std::cout << (st.empty() ? i : i - st.top().second - 1) << " ";
        st.push({tower, i});
    }
}

void taskC() {
    int n, k;
    std::cin >> n >> k;
    std::multiset<int> s;
    std::vector<int> nums(n);
    for (int i = 0; i < k; ++i) {
        std::cin >> nums[i];
        s.insert(nums[i]);
    }
    int ans = *s.begin();
    for (int i = k; i < n; ++i) {
        auto it = s.find(nums[i - k]);
        s.erase(it);
        std::cin >> nums[i];
        s.insert(nums[i]);
        ans += *s.begin();
    }
    std::cout << ans;
}

int main() {
    taskC();
}