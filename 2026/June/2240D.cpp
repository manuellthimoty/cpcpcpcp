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

void solve() {
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(3*n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
        b[i + n] = a[i];
        b[i + 2 * n] = a[i];
    }

    vector<ll> pref(3*n+1, 0);
    for (int i = 0; i <3* n; i++) pref[i + 1] = pref[i] + b[i];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int center = i+n;
        int left = center-d;
        int right = center +d;
        ll window_sum = pref[right + 1] - pref[left];
        
        ll ci = (2LL*d + 1) * a[i] - window_sum;

        if (ci > 0) {
            ans += ci;
        }
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
