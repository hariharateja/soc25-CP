#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Solution {
public:
    int f(int ind, int sum, vector<int> &nums , vector<vector<int>> &dp){
        if (ind == 0) {
            if (sum == 0 && nums[0] == 0) return 2; // +0 and -0
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }
        if (dp[ind][sum] != -1) return dp[ind][sum];

        int not_take = f(ind - 1, sum, nums, dp);
        int take = 0;
        if (nums[ind] <= sum) take = f(ind - 1, sum - nums[ind], nums, dp);

        return dp[ind][sum] = take + not_take;
    }

    int findways(vector<int> &nums, int targetSum) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));
        return f(n - 1, targetSum, nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (auto &it : nums) totalSum += it;

        // Edge case check
        if (totalSum < abs(target) || (totalSum + target) % 2 != 0) return 0;

        int subsetSum = (totalSum + target) / 2;
        return findways(nums, subsetSum);
    }
};