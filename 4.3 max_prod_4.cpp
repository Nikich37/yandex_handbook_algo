#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    if (n == 4) {
        std::cout << (long long)nums[0] * nums[1] * nums[2] * nums[3];
    }
    std::sort(nums.begin(), nums.end());
    long long ans1 = (long long)nums[0] * nums[1] * nums[2] * nums[3];
    long long ans2 = (long long)nums[n - 1] * nums[n - 2] * nums[n - 3] * nums[n - 4];
    long long ans3 = (long long)nums[0] * nums[1] * nums[n - 1] * nums[n - 2];
    std::cout << std::max(ans1, std::max(ans2, ans3));
}