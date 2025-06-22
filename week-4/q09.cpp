#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> psee = findpsee(arr);
        long long total = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - psee[i];     
            long long right = nse[i] - i;     
            total = (total + left * right % mod * arr[i] % mod) % mod;
        }
        return total;
    }

private:
    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpsee(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
};