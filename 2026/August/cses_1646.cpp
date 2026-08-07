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
    int n,q ; cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    vector<ll> pref(n+1,0);
    for(int i = 1; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    while(q--){
        int a,b; cin >> a >> b;
        cout << pref[b] - pref[a-1] << "\n";
    }
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
