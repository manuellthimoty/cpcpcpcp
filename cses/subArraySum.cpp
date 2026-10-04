#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    ll x ; cin >> x;
    vector<ll> a(n+1);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    vector<ll> prefSum(n+1,0);
    for(ll i = 1 ; i <= n ; i++){
        prefSum[i] = prefSum[i-1] + a[i];
    }
    ll ans = 0;
    unordered_map<ll,ll> indexPrefix;
    for(ll i = 0 ; i <= n ; i++){
        indexPrefix[prefSum[i]] = i;
    }
    
    for(ll i = 0 ; i <= n ; i++){
        ll complement = x + prefSum[i];
        if(complement > 0 && indexPrefix[complement]){
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}