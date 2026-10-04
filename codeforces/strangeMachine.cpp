#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; ll q; cin >> n >> q;
    string s;
    s.resize(n) ; cin >> s; 
    ll countA = 0;
    ll countB = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'A') countA++;
        if(s[i] == 'B') countB++;
    }
    vector<ll> queries(q);
    for(ll i = 0 ; i < q ; i++){
        cin >> queries[i];
    }
    if(countB == 0){
        for(ll i = 0; i < q ; i++){
            cout << queries[i] << endl;
        }
        return;
    }
    for(ll i = 0 ; i < q ; i++){
        ll cur = queries[i];
        ll j = 0;
        ll ans = 0;
        while(cur > 0){
            if(s[j] == 'A'){
                cur = cur - 1;
            }
            if(s[j] == 'B'){
                cur = cur/2;
            }
            ans++;
            j = (j + 1) % n;
        }
        cout << ans << endl;
        
    }
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