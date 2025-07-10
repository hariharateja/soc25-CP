#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; 

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); q.pop();

                for (auto& dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];

                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; 
                        q.push({nx, ny});
                        fresh--; 
                    }
                }
            }
            minutes++; 
        }

        return fresh == 0 ? minutes : -1;
    }
};