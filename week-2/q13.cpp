#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int curr = 0;
        int prev = INT_MIN;
        bool done = false;
        for(int i =0; i<nums.size();i++){
            curr = nums[i];
            if(curr < prev){
                done =true;
                return i-1;
            }
            else{
                prev = curr;
            }

        }
        if(!done){
            return nums.size()-1;
        }
        return 0;
    }
};