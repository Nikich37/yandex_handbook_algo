#include <iostream>
#include <vector>

int maxKings(int r, int c) {
    std::vector<std::vector<int>> board(r + 2, std::vector<int>(c + 2, 0));
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (board[i][j] == 1) continue;
            bool free = board[i - 1][j - 1] || board[i - 1][j] || 
            board[i - 1][j + 1] || board[i][j - 1] || board[i][j + 1] || 
            board[i + 1][j - 1] || board[i + 1][j] || board[i + 1][j + 1];
            if (!free) {
                if (i + 1 <= r && j + 1 <= c) {
                    board[i + 1][j + 1] = 1;
                } else if (i + 1 <= r && j - 1 >= 1) {
                    board[i + 1][j - 1] = 1;
                } else if (i - 1 >= 1 && j + 1 <= c) {
                    board[i - 1][j + 1] = 1;
                } else if (i - 1 >= 1 && j - 1 >= 1) {
                    board[i - 1][j - 1] = 1;
                } else if (i + 1 <= r) {
                    board[i + 1][j] = 1;
                } else if (j + 1 <= c) {
                    board[i][j + 1] = 1;
                } else if (j - 1 >= 1) {
                    board[i][j - 1] = 1;
                } else if (i - 1 >= 1) {
                    board[i - 1][j] = 1;
                } else {
                    return 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            std::cout << board[i][j] << " ";
            if (board[i][j] == 0) ans++;
        }
        std::cout << "\n";
    }
    return ans;
}

int main() {
    int r, c;
    std::cin >> r >> c;
    std::cout << maxKings(r, c);
}