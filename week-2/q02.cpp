#include<iostream>
#define ll long long
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ll int n;
    cin>>n;
    vector<int> array;
    for(ll int i=0;i<n;i++){
        ll int x;
        cin>>x;
        array.push_back(x);
    }
    ll int max_sum = array[0];
    ll int current_sum = array[0];
 
    for(ll int i = 1; i < n; i++){
        current_sum = max((ll)array[i], current_sum + array[i]);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum << "\n";
}
