#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    long long x;
    cin >> n >> x;
 
    vector<long long> a(n);
    map<long long, int> mp;
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n; ++i) {
        long long rem = x - a[i];
        if (mp.count(rem)) {
            cout << mp[rem] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        mp[a[i]] = i;
    }
 
    cout << "IMPOSSIBLE\n";
    return 0;
}
