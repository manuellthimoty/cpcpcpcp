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
    int n,k,z ; cin >> n >> k >> z;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<ll> pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    // n = 5, z = 1
    // idx maxnya = 3
    // 1 2 1 2 3
    // 1 2 3
    vector<ll> mx(n+2,0);
    mx[1] = 0;
    if(n>=2)mx[2] = a[1] + a[2];
    for(int i = 3; i <= n ; i++){
        mx[i] = max(mx[i-1],(ll)a[i] + a[i-1]);
    }

    ll ans = 0;
    for(int i = 0; i <= z ; i++){
        // sebanyak i ke kiri
        int last_idx = 1+k - 2 * i;
        if(last_idx < 1){
            continue;
        }
        ll curans = pref[last_idx] + (ll)i * mx[min(n, last_idx + 1)];
        ans = max(ans,curans);

    }
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
