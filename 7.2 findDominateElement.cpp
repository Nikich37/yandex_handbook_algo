#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
T findDominate(std::vector<T>& elems) {
    T dominate = elems[0];
    int dominateCounter = 0;
    for (int i = 0; i < elems.size(); ++i) {
        if (elems[i] == dominate) {
            dominateCounter++;
        } else {
            dominateCounter--;
        }
        if (dominateCounter == 0) {
            dominate = elems[i];
            dominateCounter = 1;
        }
    }
    return dominate;
}

template <typename T>
bool checkDominate(std::vector<T>& elems, T dominate) {
    int counter = 0;
    for (int i = 0; i < elems.size(); ++i) {
        if (elems[i] == dominate) {
            counter++;
        }
    }
    return counter > elems.size() / 2;
}

template <typename T>
bool checkThreeDominate(std::vector<T>& elems) {
    std::unordered_map<T, int> freq;
    for (int i = 0; i < elems.size(); ++i) {
        freq[elems[i]]++;
    }
    int counter = 0;
    for (const auto& [elem, frequency] : freq) {
        if (frequency > elems.size() / 4) counter++;
    }
    return counter >= 3;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::cout << checkThreeDominate(nums);
}