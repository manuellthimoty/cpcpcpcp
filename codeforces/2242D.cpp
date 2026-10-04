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
    int n,m; cin >> n >> m;
    vector<ll> a(n+1);
    for(int i = 1 ; i<= n ; i++) cin >> a[i];
    vector<ll> b(m+1);
    for(int i = 1; i <= m ; i++) cin >> b[i];
    sort(b.begin(),b.end());
    vector<ll> pref(n+1);
    pref[1] = a[1];
    for(int i = 2; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    ll ans = 0;
    ans += abs(pref[b[1]]);
    for(int i = 2 ; i <= m ; i++){
        int first = b[i-1] + 1;
        int last = b[i];
        ans += abs(pref[last] - pref[first-1]);
    }
    ans += pref[n] - pref[b[m]];
    cout << ans << endl;
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
