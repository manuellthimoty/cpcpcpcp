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
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)

// a1 a2 a3 a4 a5 a6 a7 a8
// a1 a2 .. ak-1 a[n-k+2] a[n-k+3] .. a[n]
void solve(){
    int n ; cin >> n; int k ; cin >> k;
    vector<int> a(n+5);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<ll> pref(n+5,0);
    for(int i = 1; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    ll case1 = pref[n] - pref[k-1];
    ll case2 = pref[n] - pref[n-k];
    ll case3 = pref[n-k+1] - pref[k-1];
    ll final = 0;
    int base = n-k+2;
    for(int l = 0; l <= k ; l++){
        int idx = base + k-l- 1;
        ll curSum = pref[l] - pref[0] + pref[idx] - pref[n-k-1];
        final = max(curSum,final);
    }
    for(int l = 0 ; l <= k ; l++){
        int idx_left = l - k;
        // p + k-l-1 = n -> p = n -k + l + 1
        int idx_right = n-k+l+1;
        ll curS = pref[k-1] - pref[idx_left-1] + pref[n] - pref[idx_right-1];
        final = max(final,curS);
    }
    ll ans = max({case1,case2,case3+final});
    cout << ans << endl;    
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
