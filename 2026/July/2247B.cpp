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
    ll n,k,m; cin >> n >> k >> m;
    if(k >= (m+1)){
        cout << "NO" << endl;
        return;
    }
    vector<ll> pref(n+1);
    pref[0] =0;
    ll cur = 1;
    // 5 3 5
    // 0 1 2 0 1 2
    // 0 1 2 5 6 7
    // 0 1 1 3 4 5
    // 0 1 2 3 0 -> len = 
    for(int i = 1; i <= n ; i++){
        if(i % k == 0){
            pref[i] = (ll) cur * m;
            cur++;
        }
        else pref[i] = pref[i-1] + 1;
    }
    // pref[i] - pref[i-1] = a[i]
    vector<ll> ans(n+1);
    ans[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        ans[i] = pref[i] - pref[i-1];
    }
    cout << "YES" << endl;
    for(int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
    cout << endl;

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
