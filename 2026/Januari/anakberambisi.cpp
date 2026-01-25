#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll ans = 1e6;
    for(ll i = 0 ; i < n ; i++){
        ll num ; cin >> num;
        if(num == 0){
            ans = 0;
            break;
        }
        ans = min(ans, abs(num));
    }
    cout << ans << endl;
    

    return 0;
}