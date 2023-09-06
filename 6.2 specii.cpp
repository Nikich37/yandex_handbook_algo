#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

double get_max_value_specii(std::vector<int>& weights, std::vector<int>& costs, int max_weight) {
    int weight = 0;
    std::vector<double> priority(weights.size());
    for (int i = 0; i < priority.size(); ++i) {
        priority[i] = (double)costs[i] / weights[i];
    }
    double cost = 0;
    while (max_weight > weight && *max_element(weights.begin(), weights.end()) != 0) {
        double max_prior = 0;
        int idx = 0;
        for (int i = 0; i < priority.size(); ++i) {
            if (weights[i] != 0 && priority[i] > max_prior) {
                idx = i;
                max_prior = priority[i];
            }
        }
        cost += std::min(weights[idx], max_weight - weight) * priority[idx];
        weight += std::min(weights[idx], max_weight - weight);
        weights[idx] = 0;
    }
    return cost;
}

int souvenirs(std::vector<int>& costs, int max_cost) {
    std::sort(costs.begin(), costs.end());
    int cost = 0;
    int ans = 0;
    for (int i = 0; i < costs.size(); ++i) {
        if (cost + costs[i] > max_cost) break;
        cost += costs[i];
        ans++;
    }
    return ans;
}

int main() {
    
    int n;
    int w;
    std::cin >> n >> w;
    std::vector<int> costs(n);
    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> costs[i];
        std::cin >> weights[i];
    }
    std::cout << std::fixed << std::setprecision(20) << get_max_value_specii(weights, costs, w);
}