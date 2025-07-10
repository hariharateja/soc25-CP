#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findParent(int u, vector<int>& parent) {
        if (parent[u] != u)
            parent[u] = findParent(parent[u], parent);
        return parent[u];
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1;  

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for (auto& conn : connections) {
            unionSet(conn[0], conn[1], parent, rank);
        }
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) components++;
        }

        return components - 1;
    }
};