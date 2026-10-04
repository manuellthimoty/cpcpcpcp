#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using ll = long long;
void solve() {
    ll n; cin >> n ;
    ll m = n;
    vector<ll> a(n+1,0),b(m+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    for(ll i = 1 ; i <= m ; i++) cin >> b[i];
    unordered_map <ll,vector<ll>> index;
    unordered_map <ll,vector<ll>> arrayAns;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    for(ll i = 1 ; i <= n ; i++){
        index[a[i]].push_back(i);
    }
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++){
        bool found = false;
        ll lastIndex = i;
        for(ll j = 1 ; j <= m ; j++){
            if(!found){
                if(b[j] != a[i]) {
                    dp[i][j] = 0;
                    continue;
                }
                else{
                    found = true;
                    dp[i][j] = 1;
                    arrayAns[i].push_back(b[j]);
                }
            }
            else{
                bool foundNext = false;
                for(auto &p : index[b[j]]){
                    if(p > lastIndex){
                        lastIndex = p;
                        foundNext = true;
                        break;
                    }
                }
                if(foundNext){
                    dp[i][j] = 1 + dp[i][j-1];
                    arrayAns[i].push_back(b[j]);
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
                
            }
            ans = max(ans, dp[i][j]);
        }
    }
    ll arrayAnsIdx = 0;
    // for(auto &p: arrayAns){
    //     if(p.second.size() == ans){
    //         arrayAnsIdx = p.first;
    //     }
    // }
    cout << ans << endl;
    // for (auto c : arrayAns[arrayAnsIdx]){
    //     cout << c << " ";
    // }
    // cout << endl;

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


