#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Solution {
public:
    int f(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i > j) return 0;             
        if (i == j) return 1;            

        if (dp[i][j] != -1) return dp[i][j]; 

        if (s[i] == s[j]) {
            dp[i][j] = 2 + f(i + 1, j - 1, s, dp); 
        } else {
            dp[i][j] = max(f(i + 1, j, s, dp), f(i, j - 1, s, dp)); 
        }
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        return f(0, n - 1, s, dp); 
    }
};