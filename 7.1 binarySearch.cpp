#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int binarySearch(const std::vector<T>& elems, T target) {
    int left = 0, right = elems.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (elems[middle] == target) {
            return middle;
        } else if (elems[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

template <typename T>
int lowerBound(const std::vector<T>& elems, T target) {
    int left = 0, right = elems.size() - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (elems[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    if (left == elems.size() - 1 && elems[left] < target || left == 0 && elems[0] != target) return -1;
    return left;
}

template <typename T>
int upperBound(const std::vector<T>& elems, T target) {
    int left = 0, right = elems.size() - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (elems[middle] <= target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    if (elems[left] <= target) return elems.size();
    return left;
}


bool checkCover(std::vector<int>& points, int k, int length) {
    int maxLength = 0;
    for (int point : points) {
        if (point > maxLength) {
            if (k == 0) return false;
            --k;
            maxLength = point + length;
        }
    }
    return true;
}
int minLengthSegments(std::vector<int>& points, int k) {
    std::sort(points.begin(), points.end());
    int leftPoint = points[0], rightPoint = points[points.size() - 1];
    int left = 0, right = (rightPoint - leftPoint) / k;
    while (left < right) {
        int middle = (left + right) / 2;
        if (checkCover(points, k, middle)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return left;
}



int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }
    std::cout << minLengthSegments(points, k);

}