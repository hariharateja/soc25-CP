#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int guess(int num){
    
}
class Solution {
public:
    int guessNumber(int n) {
        int low = 1 ; int high = n ;
        while(low<=high){
            long long mid = low + (high - low) / 2;
            if(guess(mid) == 0){
                return mid;
            }
            else if(guess(mid) == -1){
                high = mid - 1;
            }
            else{
                low = mid  + 1;
            }
        }

        return -1;

    }
};