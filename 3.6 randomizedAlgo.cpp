#include <iostream>
#include <vector>

void taskA() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < nums.size(); ++i) {
        std::cin >> nums[i];
    }
    int startIdx = 1;
    int pivot = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] < pivot) {
            std::swap(nums[i], nums[startIdx]);
            startIdx++;
        }
    }
    std::swap(nums[startIdx - 1], nums[0]);
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << nums[i];
    }
}

int main() {
    taskA();
}