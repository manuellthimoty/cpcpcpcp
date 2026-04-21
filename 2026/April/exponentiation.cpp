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

int MOD =1e9+7;

ll power(ll a, ll b){
    if(b == 0) return 1;
    ll mid = power(a % MOD,b/2);
    if(b % 2 == 0) return ((mid % MOD) * (mid % MOD)) % MOD;
    else return (((a % MOD) * (mid % MOD) % MOD) * (mid % MOD)) % MOD;
}

void solve(){
    ll a,b; cin >> a >> b;
    cout << power(a,b) << endl;
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
