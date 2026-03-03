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
int n;
bool isvalid(int k){
    return (k >= 0) && (k < n);
}
void solve(){
    cin >> n;
    vint a(n);
    input(a,0,n);
    vll d(n);
    d[0] = a[0];
    for(int i = 1; i < n ; i++){
        d[i] = d[i-1] + a[i];
    }
    set<ll> cur;
    cur.insert(a[0]);
    ll sum = d[n-1];
    ll target = sum /2;
    ll ans = a[0] * (sum - a[0]);
    for(int i = 1 ; i < n ; i++){
        auto positr = cur.upper_bound(d[i] - target);
        auto positl = cur.lower_bound(d[i] - target);
        if(positl !=cur.end()){
            ll curpref = d[i] - *positl;
            ans = max(ans, curpref * (sum - curpref));
        }
        if(positr != cur.end()){
            ll curpref = d[i] - *positr;
            ans = max(ans,curpref * (sum - curpref));
        }
        if(positr != cur.begin()){
            positr--;
            ll curpref = d[i] - *positr;
            ans = max(ans, curpref * (sum - curpref));
        }
        cur.insert(d[i]);
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
