#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        int maxFreq = *max_element(freq.begin(), freq.end());

        int countMaxFreq = count(freq.begin(), freq.end(), maxFreq);
        int partCount = maxFreq - 1;
        int partLength = n + 1;
        int emptySlots = partCount * partLength + countMaxFreq;

        return max((int)tasks.size(), emptySlots);
    }
};