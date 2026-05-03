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

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}
ll inv2 = modpow(2,mod-2,mod);

ll sumConsecutive(ll start, ll end){
    ll firstterm = (((end % mod) * ((end + 1) % mod)) % mod * inv2) % mod;
    ll secondterm = (((start % mod) * ((start -1) % mod)) % mod * inv2) % mod;
    ll res = firstterm - secondterm;
    if(res < 0) res += mod;
    return res;
}
void solve(){
    ll n ; cin >> n;
    ll ans = 0;
    ll ujung = 0;
    for(ll i = 1 ; i <= n/i ; i++){
        ans = (ans + (i * (n/i)) % mod) % mod;
        ujung = i;
    }
    ll strt = ujung+1;
    while(strt <= n){
        ll left = strt;
        ll curnilai = n/left;
        ll end = n/curnilai;
        ans = (ans + sumConsecutive(left,end) * (curnilai % mod)) % mod;
        strt = end+1;   
    }
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
