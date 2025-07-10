#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfsCheck(int node, vector<int> adj[] , vector<int>& vis, vector<int>& pathVis, vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,adj,vis,pathVis,check) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> helperfunction(int V , vector<int> adj[]){
        vector<int> vis(V, 0);      
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> safenodes;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i,adj,vis,pathVis,check);
            }
        }
        for(int i= 0;i<V;i++){
            if(check[i] == 1) safenodes.push_back(i);
        }
        return safenodes;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            for (int j : graph[i]) {
                adj[i].push_back(j);
            }
        }
        ans = helperfunction(V,adj);
        return ans;

    }
};