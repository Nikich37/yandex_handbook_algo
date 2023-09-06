#include <vector>
#include <iostream>


void MergeInversion(std::vector<int>& nums, int l, int half, int r, int& inversion) {
    std::vector<int> temp(r - l + 1);
    int p1 = l;
    int p2 = half + 1;
    int idx = 0;
    while(p1 <= half && p2 <= r) {
        if (nums[p1] <= nums[p2]) {
            temp[idx] = nums[p1];
            ++p1;
        } else {
            inversion += (half - p1 + 1);
            temp[idx] = nums[p2];
            ++p2;
        }
        ++idx;
    }
    while(p1 <= half || p2 <= r) {
        if (p1 <= half) {
            temp[idx] = nums[p1];
            ++p1;
        }
        if (p2 <= r) {
            temp[idx] = nums[p2];
            ++p2;
        }
        ++idx;
    }
    for (int i = l; i <= r; ++i) {
        nums[i] = temp[i - l];
    }
}

void MergeHalfInversion(std::vector<int>& nums, int l, int half, int r, int& inversion) {
    std::vector<int> temp(r - l + 1);
    int p1 = l;
    int p2 = half + 1;
    int idx = 0;
    while(p1 <= half && p2 <= r) {
        if (nums[p1] < nums[p2]) {
            temp[idx] = nums[p1];
            ++p1;
        } else {
            inversion += (half - p1 + 1);
            temp[idx] = nums[p2];
            ++p2;
        }
        ++idx;
    }
    while(p1 <= half || p2 <= r) {
        if (p1 <= half) {
            temp[idx] = nums[p1];
            ++p1;
        }
        if (p2 <= r) {
            temp[idx] = nums[p2];
            ++p2;
        }
        ++idx;
    }
    for (int i = l; i <= r; ++i) {
        nums[i] = temp[i - l];
    }
}

void MergeSort(std::vector<int>& nums, int l, int r, int& inversion) {
    if (l == r) return;
    int half = (l + r) / 2;
    MergeSort(nums, l, half, inversion);
    MergeSort(nums, half + 1, r, inversion);
    MergeHalfInversion(nums, l, half, r, inversion);
}

int SwampPebbleSort(std::vector<int>& nums) {
    int trans = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            std::swap(nums[i], nums[i + 1]);
            trans++;
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j - 1]) {
                    std::swap(nums[j], nums[j - 1]);
                    trans++;
                } else {
                    break;
                }
            }
        }
    }
    return trans;
}

int main() {

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) std::cin >> nums[i];
    int trans = SwampPebbleSort(nums);
    std::cout << trans;
}