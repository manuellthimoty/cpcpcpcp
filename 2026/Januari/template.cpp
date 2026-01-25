#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n,m,h; cin >> n >> m >> h;
    vector<ll> a(n+1,0);
    vector<ll> b(m+1,0),c(m+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    for(ll i = 1 ; i <= m ; i++) cin >> b[i] >> c[i];
    vector<ll> lastReset(n+1,0);
    vector<ll> finalArray(n+1,0);
    ll maxReset = -1;
    for(ll i = 1 ; i <= n ; i ++) finalArray[i] = a[i];
    for(ll i = 1 ; i <= m ; i++){
        if(lastReset[b[i]] < maxReset){
            lastReset[b[i]] = maxReset;
            finalArray[b[i]] = a[b[i]];
        }
        ll newVal = finalArray[b[i]] + c[i];
        if(newVal > h) {
            finalArray[b[i]] = a[b[i]];
            lastReset[b[i]] = i;
            maxReset = max(maxReset,lastReset[b[i]]);
        }
        else{
            finalArray[b[i]] = newVal;
        }
    }
    for(ll i = 1 ; i <= n ; i++){
        if(lastReset[i] < maxReset){
            finalArray[i] = a[i]; 
        }
    }
    for(ll i = 1 ; i <= n ; i++){
        cout << finalArray[i] << " ";
    }
    cout << endl;
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