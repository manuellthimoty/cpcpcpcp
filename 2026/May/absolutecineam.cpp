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
    int n ; cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> b[i];
    }
    vector<int> mn(n);
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans += max(a[i],b[i]);
    }
    int mxmin = min(a[0],b[0]);
    for(int i = 1 ; i < n ; i++){
        mxmin = max(mxmin, min(a[i],b[i]));
    }
    cout << ans + mxmin << endl;
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
