#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <set>

void taskA() {
    int n;
    std::cin >> n;
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        int request;
        std::cin >> request;
        int num;
        std::cin >> num;
        if (request == 1) {
            s.insert(num);
        } else {
            std::cout << s.count(num) << "\n";
        }
    }
}

void taskB() {
    int n;
    std::cin >> n;
    std::unordered_map<std::string, int> m;
    int ans = 0;
    for (int k = 0; k < n; ++k) {
        std::string word;
        std::cin >> word;
        std::string new_word = word;
        ans -= m[word] * word.size();
        m[word]++;
        for (int i = 0; i < word.size(); ++i) {
            new_word[i] = '.';
            ans += m[new_word];
            m[new_word]++;
            new_word[i] = word[i];
        }
    }
    std::cout << ans;
}

int main() {
    taskB();
}