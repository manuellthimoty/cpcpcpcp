#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

void solve(){
    ll ans = 0;
    ll curmod = 10;
    vector<ll> v(101,1);
    vector<ll> m(101,1);
    for(ll i = 1; i <= 17 ; i++){
        m[i] = 10 * m[i-1];
    }
    ll n = 100;
    ll cur = 1;
    for(ll i = 1; i <= n ; i++){
        ll f = i;
        while(cur % 10 == 0){
            cur = cur/10;
        }
        while( f % 10 == 0){
            f = f/10;
        }
        for(int i = 1; i <= 100 ; i++){
            v[i] = (v[i] * (f % m[i])) % m[i]; 
        }
    }
    for(auto dig : v) cout << dig << " ";
    // for(auto dig : v){
    //     ll c = dig;
    //     while(c % 10 == 0){
    //         c = c/10;
    //     }
    //     ans += c;
    //     cout << c << endl;
    // }
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
