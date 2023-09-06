#include <iostream>
#include <vector>

template <typename T>
void printMatrix(const std::vector<T>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (j != 0) {
                std::cout << " ";
            }
            std::cout << matrix[i][j];
        }
        std::cout << "\n";
    }
}

void taskA() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graphStops(n, std::vector<int>(n));
    std::vector<std::vector<int>> graphStops2(n, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int k = 0;
        std::cin >> k;
        int prevStop = 0;
        std::vector<int> stops;
        stops.reserve(k);
        std::cin >> prevStop;
        prevStop--;
        stops.push_back(prevStop);
        for (int j = 0; j < k - 1; ++j) {
            int stop = 0;
            std::cin >> stop;
            stop--;
            graphStops[prevStop][stop] = 1;
            graphStops[stop][prevStop] = 1;
            prevStop = stop;
            stops.push_back(stop);
        }
        for (int j = 0; j < k; ++j) {
            for (int q = j + 1; q < k; ++q) {
                graphStops2[stops[j]][stops[q]] = 1;
                graphStops2[stops[q]][stops[j]] = 1;
            }
        }
    }
    printMatrix(graphStops);
    printMatrix(graphStops2);
}

void taskB() {
    const char VISITED = '*';
    const char EMPTY = '.';
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> roomGrid(n, std::vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> roomGrid[i][j];
        }
    }
    int r, c;
    std::cin >> r >> c; r--; c--;
    roomGrid[r][c] = VISITED;
    int moves;
    std::cin >> moves;
    int direction = 0;
    for (int i = 0; i < moves; ++i) {
        char move;
        std::cin >> move;
        if (move == 'R') {
            direction = (direction + 1) % 4;
        } else if (move == 'L') {
            direction = (direction - 1) == -1 ? 3 : direction - 1;
        } else {
            if (direction == 0 && r > 0 && (roomGrid[r - 1][c] == EMPTY || roomGrid[r - 1][c] == VISITED)) {
                r--;
            } else if (direction == 1 && c <= m - 2 && (roomGrid[r][c + 1] == EMPTY || roomGrid[r][c + 1] == VISITED)) {
                c++;
            } else if (direction == 2 && r <= n - 2 && (roomGrid[r + 1][c] == EMPTY || roomGrid[r + 1][c] == VISITED)) {
                r++;
            } else if (direction == 3 && c > 0 && (roomGrid[r][c - 1] == EMPTY || roomGrid[r][c - 1] == VISITED)) {
                c--;
            }
            roomGrid[r][c] = VISITED;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (roomGrid[i][j] == VISITED) {
                ans++;
            }
        }
    }
    std::cout << ans;
}


int main() {
    taskB();
}