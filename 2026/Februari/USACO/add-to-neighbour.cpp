#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n ; cin >> n;
    vector<ll> a(n+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    ll sum = 0;
    for(ll i = 1 ; i <= n ; i++) sum += a[i];
    
    vector<ll> facts;
    for(ll i = 1 ; i * i <= sum ; i++){
        if(sum % i == 0){
            if(i <= n) facts.push_back(i);
            if(i!= sum/i && sum / i <= n) facts.push_back(sum/i);
        }
    }
    ll ans = 1e9;
    for(auto fac : facts){
        ll target = sum / fac;
        ll curSum  = 0;
        ll groups = 0;
        bool valid = true;
        for(ll i = 1 ; i <= n ; i++){
            curSum += a[i];
            if(curSum == target){
                groups++;
                curSum = 0;
            }
            else if(curSum > target){
                valid = false;
                break;
            }
        }
        if(curSum!= 0) valid = false;
        if(valid){
            ans = min(ans, n - groups);
        }
    }
    cout << ans << endl;
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