#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[course] == 1) return false; 
        if (visited[course] == 2) return true;  

        visited[course] = 1; 

        for (int neighbor : graph[course]) {
            if (!dfs(neighbor, graph, visited))
                return false;
        }

        visited[course] = 2; 
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);  
        }

        vector<int> visited(numCourses, 0); 

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, graph, visited))
                return false;
        }

        return true;
    }
};