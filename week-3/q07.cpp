#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfMax(nums) - sumOfMin(nums);
    }

private:
    long long sumOfMax(const vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, n), prev(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res += (long long)nums[i] * left * right;
        }
        return res;
    }

    long long sumOfMin(const vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, n), prev(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res += (long long)nums[i] * left * right;
        }
        return res;
    }
};