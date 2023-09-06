#include <iostream>
#include <vector>
#include <algorithm>

std::string greatestNumber(std::vector<std::string>& nums) {
    std::sort(nums.begin(), nums.end(), [] (const auto& num1, const auto& num2) {
        return num1 + num2 > num2 + num1;
    });
    std::string ans;
    for (std::string& num : nums) {
        ans += num;
    }
    return ans;
}

int maxGames(std::vector<int>& robots, int k) {
    int robot = robots[k - 1];
    std::sort(robots.begin(), robots.end());
    int robotIdx = 0;
    for (int i = 0; i < robots.size(); ++i) {
        if (robots[i] == robot) {
            robotIdx = i;
            break;
        }
    }
    int left = robotIdx;
    int right = robots.size() - robotIdx - 1;
    int ans = 0;
    while(left) {
        if (right == 1) {
            left -= 1;
        } else if ((left + right) % 2) {
            right = (right + 1) / 2;
        } else {
            right /= 2;
        }
        left /= 2;
        ans++;
    }
    return ans;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> robots(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> robots[i];
    }
    std::cout << maxGames(robots, k);
}

