#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights)
            adj[f[0]].push_back({f[1], f[2]});
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<>> pq;

        pq.push({0, src, 0});
        vector<int> stopsRecord(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top();
            pq.pop();

            if (city == dst) return cost;

            if (stops > stopsRecord[city] || stops > k) continue;

            stopsRecord[city] = stops;

            for (auto [next, price] : adj[city]) {
                pq.push({cost + price, next, stops + 1});
            }
        }

        return -1;
    }
};