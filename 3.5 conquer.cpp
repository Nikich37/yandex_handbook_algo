#include <iostream>
#include <vector>
#include <set>

template <typename T>
void choiceSort(std::vector<T>& elems) {
    for (int i = 0; i < elems.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < elems.size(); ++j) {
            if (elems[j] < elems[min]) {
                min = j;
            }
        }
        std::swap(elems[min], elems[i]);
    }
}

void taskA() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    choiceSort(nums);
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            std::cout << " "; 
        }
        std::cout << nums[i];
    }
}

template <typename T>
std::vector<T> merge(std::vector<std::vector<T>>& sequences) {
    std::multiset<T> elems;
    for (int i = 0; i < sequences.size(); ++i) {
        std::vector<T>& sequence = sequences[i];
        for (int j = 0; j < sequence.size(); ++j) {
            elems.insert(sequence[j]);
        }
    }
    return std::vector<T>(elems.begin(), elems.end());
}

void taskB() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> sequences(n);
    for (int i = 0; i < n; ++i) {
        int q;
        std::cin >> q;
        for (int j = 0; j < q; ++j) {
            int num;
            std::cin >> num;
            sequences[i].push_back(num);
        }
    }
    std::vector<int> ans = merge(sequences);
    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << ans[i];
    }
}

template<typename T>
std::vector<T> merge(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> merged(v1.size() + v2.size());
    int p1 = 0, p2 = 0;
    int idx = 0;
    while(p1 < v1.size() || p2 < v2.size()) {
        if (p1 < v1.size() && p2 != v2.size()) {
            if (v1[p1] < v2[p2]) {
                merged[idx] = v1[p1];
                p1++;
            } else {
                merged[idx] = v2[p2];
                p2++;
            }
        } else if (p1 < v1.size()) {
            merged[idx] = v1[p1];
            p1++;
        } else {
            merged[idx] = v2[p2];
            p2++;
        }
        idx++;
    }
    return merged;
}

template <typename T>
void mergeSort(std::vector<T>& elems) {
    if (elems.size() <= 1) return;
    int half = elems.size() / 2;
    std::vector<T> first = std::vector<T>(elems.begin(), elems.begin() + half);
    std::vector<T> second = std::vector<T>(elems.begin() + half, elems.end());
    mergeSort(first);
    mergeSort(second);
    elems = merge(first, second);
}

void taskC() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    mergeSort(nums);
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << nums[i];
    }
}
int main() {
    taskC();
}