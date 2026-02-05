#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

void solve() {
    ll n ; cin >> n;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    if(a[0] != 1 && a[n-1] !=1){
        NO;  
        return; 
    }
    ll minimum = n;
    for(ll i = 1 ; i < n - 1 ; i++){
        minimum = min(minimum,a[i]);
    }
    if(minimum < a[0] || minimum < a[n-1]){
        NO;
        return;
    }
    YES;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}