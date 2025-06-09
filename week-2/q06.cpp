#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int temp = -1;
        int count =0;
        for(int i = 0;i<n;i++){
            for(int j=temp+1;j<m;j++){
                if(s[i]==t[j]){
                    count++;
                    if(temp>j){
                        return false;
                    }
                    else{
                        temp=j;
                        break;
                    }
                }
            }
        }
        if(count!=n){
            return false;
        }
        else{
            return true;
        }
    }
};