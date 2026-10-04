#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll isOdd(ll n){
    return (((n % 2) + 2) % 2 == 1);
}

ll isEven(ll n){
    return (((n % 2) + 2) % 2 == 0);
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    ll minInf = -1e6;
    vector<ll> dp_odd(n, minInf + 1), dp_even(n,minInf); // maximum  ending at index i
    vector<ll> max_odd(n, minInf + 1), max_even(n,minInf); // maximum odd or even of dp[1],dp[2]...,dp[i]
    if(isOdd(a[0])){
        dp_odd[0] = a[0];
        max_odd[0] = a[0];
    }
    if(isEven(a[0])){
        dp_even[0] = a[0];
        max_even[0] = a[0];
    }
    for(ll i = 1 ; i < n ; i++){
        if(isOdd(a[i])){
            dp_odd[i] = max(a[i],a[i] + max_even[i-1]);
            dp_even[i] = (a[i] + max_odd[i-1]);
            max_even[i] = max(max_even[i-1],dp_even[i]);
            max_odd[i] = max(max_odd[i-1],dp_odd[i]);
        }
        else{
            // a[i] even
            dp_odd[i] = a[i] + max_odd[i-1];
            dp_even[i] = max(a[i],a[i]+max_even[i-1]);
            max_even[i] = max(max_even[i-1],dp_even[i]);
            max_odd[i] = max(max_odd[i-1],dp_odd[i]);
        }
    }
    cout << max_odd[n-1] << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}