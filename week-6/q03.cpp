#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited, adj))
                    return true;
            }
            else if (neighbor != parent) {
                // Visited and not the parent → cycle
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(i, -1, visited, adj))
                    return true;
            }
        }

        return false;
    }
};