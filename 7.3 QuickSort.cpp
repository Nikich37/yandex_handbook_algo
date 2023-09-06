#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::pair<int, int> Partition(std::vector<T>& elems, int left, int right, int pivotIndex) {
    std::vector<int> temp;
    temp.reserve(right - left + 1);
    int elem = elems[pivotIndex];
    for (int i = left; i <= right; ++i) {
        if (elems[i] < elem) {
            temp.push_back(elems[i]);
        }
    }
    int startIdx = temp.size() + left;
    for (int i = left; i <= right; ++i) {
        if (elems[i] == elem) {
            temp.push_back(elems[i]);
        }
    }
    int endIdx = temp.size() - 1 + left;
    for (int i = left; i <= right; ++i) {
        if (elems[i] > elem) {
            temp.push_back(elems[i]);
        }
    }
    for (int i = left; i <= right; ++i) {
        elems[i] = temp[i - left];
    }
    return {startIdx, endIdx};
}

template <typename T>
void RandomizedQuickSort(std::vector<T>& elems, int left, int right) {
    if (right <= left) return;
    int pivotIdx = rand() % (right - left + 1) + left;
    std::pair<int, int> partition = Partition(elems, left, right, pivotIdx);
    RandomizedQuickSort(elems, left, partition.first - 1);
    RandomizedQuickSort(elems, partition.second + 1, right);
}

template <typename T>
void RandomizedQuickSortCalls(std::vector<T>& elems, int left, int right, int& calls) {
    calls += 1;
    if (right <= left) return;
    int pivotIdx = (left + right) / 2;
    std::pair<int, int> partition = Partition(elems, left, right, pivotIdx);
    RandomizedQuickSortCalls(elems, left, partition.first - 1, calls);
    RandomizedQuickSortCalls(elems, partition.second + 1, right, calls);
}

void stressTest() {
    srand(time(0));
    int n = 15;
    while (true) {
        std::vector<int> nums1(n);
        std::vector<int> nums2(n);
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            int temp = rand() % 15;
            nums1[i] = temp;
            nums2[i] = temp;
            nums[i] = temp;
        }
        std::sort(nums1.begin(), nums1.end());
        RandomizedQuickSort(nums2, 0, nums2.size() - 1);
        if (nums1 != nums2) {
            for (int num : nums) {
                std::cout << num << " ";
            }
            break;
        }
    }
    
}



std::vector<int> badCase(int n) {
    if (n == 1) return {1};
    std::vector<int> prev = badCase(n - 1);
    int middle = (n - 1) / 2;
    std::swap(prev[middle], prev[n - 2]);
    prev.insert(prev.begin() + middle, n);
    return prev;
}

void stressTestBadCase() {
    int n = 2;
    while (true) {
        std::vector<int> ans = badCase(n);
        int calls = 0;
        RandomizedQuickSortCalls(ans, 0, ans.size() - 1, calls);
        ans = badCase(n);
        
        std::cout << "\n" << calls << "\n";
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                std::cout << " ";
            }
            std::cout << ans[i];
        }
        if (calls <= n) {
            break;
        }
        n++;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans = badCase(n);
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << ans[i];
    }
}