#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)
ll MOD = 998244353;

vector<ull> powers10(20);
ll gcd(ll a, ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}
void precompute(){
    powers10[0] = 1;
    for(ll i = 1; i <= 19 ; i++) powers10[i] = 10ULL * powers10[i-1];

}

void solve(){
    ll n,m ; cin >> n >> m;
    if(n < 10){
        ll g1 = gcd(m,9);
        ll first = (n * g1)/m;
        first = first % MOD;
        ll second = n;
        ll ans = first * second;
        ans %= MOD;
        cout << ans << endl;
        return;
    }
    ll MX = 0;
    for(ll i = 0 ; i <= 18 ; i++){
        if(powers10[i] == (ull) n){
            MX = i;
            break;
        }
        if(powers10[i] > (ull) n){
            MX = i-1;
            break;
        }
    }
    vector<ll> g(20);
    for(ll i = 1 ; i <= 19 ; i++){
        ll mod_val = powers10[i] % m;
        g[i] = gcd(m, (mod_val - 1 + m) % m);
    }
    ll ans = 0;
    for(ll i = 1 ; i <= MX ; i++){
        ll first = n;
        first = first / (m/g[i]);
        first %= MOD;
        first = first * 9;
        first %= MOD;
        first = first * (powers10[i-1] % MOD);
        first %= MOD;
        ans = ans + first;
        ans %= MOD;
    }
    ll lst = n;
    lst = lst/(m/g[MX+1]);
    lst %= MOD;
    // cout << "lst : " << lst << endl;
    ll scnd = n - powers10[MX] + 1;
    scnd %= MOD;
    lst = lst * scnd;
    lst %= MOD;
    ans += lst;
    ans %= MOD;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
