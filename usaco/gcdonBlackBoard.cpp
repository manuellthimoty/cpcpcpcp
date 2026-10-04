#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a == 1 || b ==1 ) return 1;
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vector<ll> a(n+1);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    vector<ll> left(n+1);
    left[1] = a[1];
    vector<ll> right(n+1);
    right[n] = a[n];
    for(ll i = 2 ; i <= n ; i++){
        left[i] = gcd(left[i-1],a[i]);
    }
    for(ll i = n - 1 ; i >= 1 ; i--){
        right[i] = gcd(right[i+1],a[i]);
    }
    ll ans = max({left[n],left[n-1],right[2]});
    for(ll i = 2 ; i <= n-1 ; i++){
        ll cur = gcd(left[i-1],right[i+1]);
        ans = max(ans,cur);
    }
    cout << ans << endl;
    

    return 0;
}