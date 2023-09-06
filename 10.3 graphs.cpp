#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// проверка на ацикличность
bool dfs_cycle(std::vector<std::vector<int>>& graph, std::vector<int>& visited, int n) {
    visited[n] = 1;
    for (int i = 0; i < graph[n].size(); ++i) {
        int to = graph[n][i];
        if (visited[to] == 0) {
            if (dfs_cycle(graph, visited, to)) {
                return true;
            } 
        } else if (visited[to] == 1) {
            return true;
        }
    }
    visited[n] = 2;
    return false;
}

void dfs(std::vector<std::vector<int>>& graph, std::vector<int>& visited, int n) {
    for (int i = 0; i < graph[n].size(); ++i) {
        int to = graph[n][i];
        if (visited[to] == 0) {
            visited[to] = 1;
            dfs(graph, visited, to);
        }
    }
}

// проверка на связность
bool dfs_connectivity(std::vector<std::vector<int>>& graph, std::vector<int>& visited, int n) {
    for (int i = 0; i < graph[n].size(); ++i) {
        int to = graph[n][i];
        visited[to] = 1;
        dfs(graph, visited, to);
    }
    return std::all_of(visited.begin(), visited.end(), [](int x) {return x == 1;});
}



void taskA() {
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    std::vector<std::vector<int>> graph_undirected(n);
    for (int i = 0; i < m; ++i) {
        int player1, player2, winner;
        std::cin >> player1 >> player2 >> winner;
        player1--; player2--; winner--;
        if (player1 == 1) {
            graph[player1].push_back(player2);
        } else {
            graph[player2].push_back(player1);
        }
        graph_undirected[player1].push_back(player2);
        graph_undirected[player2].push_back(player1);
    }
    std::vector<int> v1(n);
    std::vector<int> v2(n);
    if (!dfs_connectivity(graph_undirected, v1, 0) || dfs_cycle(graph, v2, 0)) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
    }

}

void taskA2() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> levels(n);
    for (int i = 0; i < m; ++i) {
        int player1, player2, winner;
        std::cin >> player1 >> player2 >> winner;
        player1--; player2--; winner--;
        if (player1 == 1) {
            levels[player1] = std::max(levels[player1], levels[player2] + 1);
        } else {
            levels[player2] = std::max(levels[player2], levels[player1] + 1);
        }
    }
    std::unordered_set<int> unique(levels.begin(), levels.end());
    if(unique.size() == levels.size()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
int main() {
    taskA2();
}