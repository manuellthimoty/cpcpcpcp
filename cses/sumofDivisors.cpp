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
int mod = 1e9+7;
ll sumtoN(ll k) {
    return (k*(k+1)/2) % mod;
}

void solve(){
    ll n ; cin >> n;
    ll ans = 0;
    ll last = 0;
    for(ll i = 1 ; i*i <= n ; i++){
        ans += (sumtoN(i) + (n/i) * i) % mod;
        last = i;
    }
    
    ll k = last;
    ans -= k * sumtoN(k);
    cout << ans << endl;
       
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
