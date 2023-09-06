#include <iostream>
#include <vector>

// d = 1, 5, 10
std::vector<std::pair<int, std::vector<int>>> simple_change(int money) {
    int tens = money / 10;
    int fives = money / 5;
    int ones = money;
    std::vector<std::pair<int, std::vector<int>>> ans;
    for (int i = 0; i <= ones; ++i) {
        for (int j = 0; j <= fives; ++j) {
            for (int k = 0; k <= tens; ++k) {
                if (i * 1 + j * 5 + k * 10 == money) {
                    std::vector<int> cur;
                    for (int l = 0; l < i; ++l) {
                        cur.push_back(1);
                    }
                    for (int l = 0; l < j; ++l) {
                        cur.push_back(5);
                    }
                    for (int l = 0; l < k; ++l) {
                        cur.push_back(10);
                    }
                    ans.push_back({i + k + j, cur});
                }
            }
        }
    }
    return ans;
}

// d = 1, 5, 10, 20, 50
std::pair<int, std::vector<int>> min_change(int money) {

    int fifths = money / 50;
    money %= 50;
    int ones = money % 5;
    int fives = (money % 10) / 5;
    int tens = (money % 20) / 10;
    int twenties = money / 20;
    
    std::vector<int> cur;
    for (int i = 0; i < fifths; ++i) {
        cur.push_back(50);
    }
    for (int i = 0; i < twenties; ++i) {
        cur.push_back(20);
    }
    for (int i = 0; i < tens; ++i) {
        cur.push_back(10);
    }
    for (int i = 0; i < fives; ++i) {
        cur.push_back(5);
    }
    for (int i = 0; i < ones; ++i) {
        cur.push_back(1);
    }
    
    return {ones + fives + tens + fifths, cur};
}

int main() {
    int n;
    std::cin >> n;
    std::pair<int, std::vector<int>> ans = min_change(n);
    std::cout << ans.first << "\n";
    for (int i = 0; i < ans.second.size(); ++i) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << ans.second[i];
    }
}