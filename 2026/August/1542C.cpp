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

ll gcd(ll a, ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)) *b;
}

void solve(){
    ll n ; cin >> n;
    ll ans = 2 * (n - n/2);
    ll MOD = 1e9+7;
    ll cur_lcm = 2;
    for(ll i = 3 ;; i++){
        ll cnt = n/cur_lcm;

        cur_lcm = lcm(cur_lcm,i);
        cnt -= n/cur_lcm;
        // if(cnt <= 0) break;
        ans += (i % MOD * cnt % MOD) ;
        ans %= (ll) MOD;
        if(n / cur_lcm == 0) break;

    }
    cout << ans << '\n';
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
