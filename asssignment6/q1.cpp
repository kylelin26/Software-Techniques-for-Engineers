#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> graph(n);

    for (auto& flight : flights) {
        int from = flight[0], to = flight[1], price = flight[2];
        graph[from].push_back({to, price});
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, src, 0});

    vector<int> stops(n, INT_MAX);

    while (!pq.empty()) {
        auto [cost, city, stop] = pq.top();
        pq.pop();

        if (city == dst) return cost;
        if (stop > k || stop >= stops[city]) continue;

        stops[city] = stop;

        for (auto& [next, price] : graph[city]) {
            pq.push({cost + price, next, stop + 1});
        }
    }

    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };
    int src = 0, dst = 3, k = 1;

    int result = findCheapestPrice(n, flights, src, dst, k);
    cout << "Output: " << result << endl;

    return 0;
}
