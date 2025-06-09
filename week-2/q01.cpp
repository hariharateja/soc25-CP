#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
 
    vector<ll> applicants(n);
    vector<ll> apartments(m);
 
    for (ll i = 0; i < n; ++i) cin >> applicants[i];
    for (ll i = 0; i < m; ++i) cin >> apartments[i];
 
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
 
    ll count = 0;
    ll i = 0, j = 0;
 
    while (i < n && j < m) {
        if (abs(applicants[i] - apartments[j]) <= k) {
            count++;
            i++;
            j++;
        } else if (apartments[j] < applicants[i] - k) {
            j++;
        } else {
            i++;
        }
    }
 
    cout << count << "\n";
    return 0;
}