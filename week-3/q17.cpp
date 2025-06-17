#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, count] : freq) {
            pq.push({count, ch});
        }

        string result;
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            result += string(count, ch); 
        }

        return result;
    }
};