#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int output = 0;
        for(int i=0;i<nums.size();i++){
            output = output^nums[i];
        }
        return output;
    }
};