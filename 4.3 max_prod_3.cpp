#include <iostream>
#include <vector>

int bruteforce(std::vector<int>& nums) {
    long long ans = LLONG_MIN;
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                ans = std::max(ans, (long long)nums[i] * nums[j] * nums[k]);
            }
        }
    }
    return ans;
}

int test_solution(std::vector<int>& nums) {
    int n = nums.size();
    long long num1, num2, num3, minNum1, minNum2, minNum3;
    num1 = nums[0];
    num2 = nums[1];
    num3 = nums[2];
    minNum1 = num1;
    minNum2 = num2;
    minNum3 = num3;

    if (minNum1 > minNum2) {
        std::swap(minNum1, minNum2);
    }
    if (minNum1 > minNum3) {
        std::swap(minNum1, minNum3);
    }
    if (minNum2 > minNum3) {
        std::swap(minNum2, minNum3);
    }

    if (num1 < num2) {
        std::swap(num1, num2);
    }
    if (num1 < num3) {
        std::swap(num1, num3);
    }
    if (num2 < num3) {
        std::swap(num2, num3);
    }

    for (int i = 3; i < n; ++i) {
        long long num, temp;
        temp = nums[i];
        num = temp;
        if (num < minNum1) {
            std::swap(num, minNum1);
            std::swap(num, minNum2);
        } else if (num < minNum2) {
            std::swap(num, minNum2);
            std::swap(num, minNum3);
        } else if (num < minNum3) {
            minNum3 = num;
        }
        
        num = temp;
        if (num > num1) {
            std::swap(num, num1);
            std::swap(num, num2);
            std::swap(num, num3);
        } else if (num > num2) {
            std::swap(num, num2);
            std::swap(num, num3);
        } else if (num > num3) {
            num3 = num;
        }
    }
    if (n >= 4) {
        std::cout << "\n" << num1 << " " << num2 << " " << num3 << ", " << minNum1 << " " << minNum2 << " " << minNum3 << "\n";
        return std::max(num1 * num2 * num3, minNum1 * minNum2 * num1);
        
    } else {
        return num1 * num2 * num3;
    }
}

void stressTest(int n, int m) {
    std::vector<int> nums(10);
    srand(time(0));
    while (true) {
        for (int i = 0; i < 10; ++i) {
            nums[i] = rand() % (m - n + 1) + n;
            std::cout << nums[i] << " ";
        }
        long long res = test_solution(nums);
        long long ans = bruteforce(nums);
        std::cout << "\nanswer: " << ans << "\n";
        std::cout << "result: " << res << "\n";
        if (res != ans) break;
    }
}

int main() {
    
    stressTest(-10, 10);
    
}