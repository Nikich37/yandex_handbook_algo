#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <set>

void taskA() {
    int q;
    std::cin >> q;
    std::list<int> list;
    for (int i = 0; i < q; ++i) {
        int request;
        std::cin >> request;
        if (request == 1) {
            int x, y;
            std::cin >> x >> y;
            auto it = list.begin();
            for (int j = 0; j < x; ++j) {
                it++;
            }
            list.insert(it, y);
        } else if (request == 2) {
            int x; 
            std::cin >> x;
            auto it = list.begin();
            for (int j = 0; j < x - 1; ++j) {
                it++;
            }
            std::cout << *it << "\n";
        } else {
            int x;
            std::cin >> x;
            auto it = list.begin();
            for (int j = 0; j < x - 1; ++j) {
                it++;
            }
            list.erase(it);
        }
    }
}

void taskB() {
    int n;
    std::cin >> n;
    std::set<int> s;
    std::vector<int> nums(n);
    std::unordered_map<int, int> pos;
    int num;
    std::cin >> num;
    s.insert(num);
    pos[num] = 0;
    nums[0] = num;
    std::cin >> num;
    s.insert(num);
    
    nums[1] = num;
    if (nums[1] != nums[0]) {
        pos[num] = 1;
    }
    
    std::pair<int, int> ans1{0, 1};
    std::pair<int, int> ans2{0, 1};
    
    for (int i = 2; i < n; ++i) {
        std::cin >> num;
        nums[i] = num;
        int maxNum = *(--s.end());
        int minNum = *s.begin();
        if (nums[ans1.first] - nums[ans1.second] > minNum - num) {
            ans1 = {pos[minNum], i};
        }
        if (nums[ans2.first] - nums[ans2.second] < maxNum - num) {
            ans2 = {pos[maxNum], i};
        }
        if (!pos.count(num)) {
            pos[num] = i;
        }
        s.insert(num);
    }
    
    std::cout << ans1.first + 1 << " " << ans1.second + 1 << "\n";
    std::cout << ans2.first + 1 << " " << ans2.second + 1;
}

std::vector<int> dp(const std::vector<int> nums) {
    int n = nums.size();
    std::set<int> s;
    std::unordered_map<int, int> pos;
    s.insert(nums[0]);
    pos[nums[0]] = 0;
    s.insert(nums[1]);
    pos[nums[1]] = 1;
    std::pair<int, int> ans1{0, 1};
    std::pair<int, int> ans2{0, 1};
    
    for (int i = 2; i < n; ++i) {
        int num = nums[i];
        int maxNum = *(--s.end());
        int minNum = *s.begin();
        if (nums[ans1.first] - nums[ans1.second] > minNum - num) {
            ans1 = {pos[minNum], i};
        }
        if (nums[ans2.first] - nums[ans2.second] < maxNum - num) {
            ans2 = {pos[maxNum], i};
        }
        if (!pos.count(num)) {
            pos[num] = i;
        }
        s.insert(num);
    }
    
    return {ans1.first, ans1.second, ans2.first, ans2.second};
}

std::vector<int> bruteForce(const std::vector<int>& nums) {
    std::pair<int, int> ans1 = {0, 1};
    std::pair<int, int> ans2 = {0, 1};
    int min = nums[0] - nums[1];
    int max = nums[0] - nums[1];
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (min > nums[i] - nums[j]) {
                ans1 = {i, j};
                min = nums[i] - nums[j];
            }
            if (max < nums[i] - nums[j]) {
                ans2 = {i, j};
                max = nums[i] - nums[j];
            }
        }
    }
    return {ans1.first, ans1.second, ans2.first, ans2.second};
}
void stressTest() {
    srand(time(0));
    while (true) {
        int n = 10;
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = rand() % 100000 + 1;
        }
        std::vector<int> ans = dp(nums);
        std::vector<int> correct = bruteForce(nums);
        if (ans != correct) {
            for (int i = 0; i < n; ++i) {
                std::cout << nums[i] << " ";
            }
            std::cout << "\n" << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
            std::cout << correct[0] << " " << correct[1] << " " << correct[2] << " " << correct[3];
            break;
        }
    } 
}
int main() {
    stressTest();
}