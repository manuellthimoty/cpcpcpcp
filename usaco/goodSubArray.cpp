#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s ; 
        s.resize(n);
        cin >> s;
        vector<ll> a(n+1,0);
        for(ll i = 1 ; i <= n ; i++){
            a[i] = s[i-1] - '0';
            // cout << a[i] << " ";
        }
        vector<ll> pref(n+1,0);
        for(ll i = 1 ; i <= n ; i++){
            pref[i] = a[i] + pref[i-1];
        }
        vector<ll> dif(n+1,0);
        for(ll i = 1; i <= n ; i++){
            dif[i] = pref[i] -i;
            // cout << dif[i] << " ";
        }
        map<ll,ll> count;
        count[0] = 1;
        ll ans = 0;
        for(ll i = 1; i <= n ; i++){
            ans += count[dif[i]];
            count[dif[i]] ++;
            // cout << count[dif[i]] << " ";
        }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}