#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result;

        while (!pq.empty()) {
            auto [count1, char1] = pq.top(); pq.pop();

            int n = result.size();
            if (n >= 2 && result[n - 1] == char1 && result[n - 2] == char1) {
                if (pq.empty()) break; 

                auto [count2, char2] = pq.top(); pq.pop();
                result += char2;
                if (--count2 > 0) pq.push({count2, char2});

                pq.push({count1, char1});
            } else {
                result += char1;
                if (--count1 > 0) pq.push({count1, char1});
            }
        }

        return result;
    }
};