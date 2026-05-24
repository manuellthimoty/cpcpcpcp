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
const int mxA = 1e6;
int spf[mxA + 1];

vector<vector<int>> primefact(mxA+1);
ll modpow(ll a, ll b){
    ll res = 1;

    while(b){
        if(b & 1)
            res = res * a;

        a = a * a;
        b >>= 1;
    }

    return res;
}
void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    for (int i = 2; i <= mxA; i++) {
        int temp = i;
        while (temp > 1) {
            int p = spf[temp];
            primefact[i].push_back(p);
            while (temp % p == 0) temp /= p;
        }
    }
}
int cntFactors(ll n){
    int cnt = 0;
    for(ll i = 2; i * i <= n ; i++){
        if(n % i == 0){
            cnt++;
            if(n / i != i){
                cnt++;
            }
        }
    }
    return cnt; 
}

 ll gcd(ll a, ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a% b);
 }
 ll lcm(ll a, ll b){
    return a * (b/gcd(a,b));
 }


void solve() {
    int n; 
    cin >> n;
    vector<ll> d(n);
    for(int i = 0 ; i < n ; i++) cin >> d[i];
    
    sort(d.begin(), d.end());
    
    ll ans = 1;
    for(int i = 0 ; i < n ; i++){
        ans = lcm(ans, d[i]);
    }
    
    if(ans == d[n-1]) {
        ans = ans * d[0];
    }
    
    if(cntFactors(ans) != n) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // init();
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
