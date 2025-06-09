#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> coins(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
 
    sort(coins.begin(), coins.end());
 
    long long target = 1;
    for (int i = 0; i < n; ++i) {
        if (coins[i] > target) {
            break;
        }
        target += coins[i];
    }
 
    cout << target << endl;
 
    return 0;
}