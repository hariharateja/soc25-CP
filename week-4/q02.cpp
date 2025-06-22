#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Solution {
private:
    int prev = 1;
    int prev2 = 0;
public:
    int fib(int n) {
        for(int i=1;i<=n;i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev2;
    }
};