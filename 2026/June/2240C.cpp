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
    int n;
    cin >> n;
    vector<ll> a(n);
    int nzer = 0;
    ll xor_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            nzer++;
        }
        xor_sum ^= a[i];
    }

    if (nzer <= 1) {
        cout << 0 << endl;
    } 
    else if (xor_sum == 0) {
        cout << 1 << endl;
    } 
    else {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if ((xor_sum ^ a[i]) < a[i]) {
                ans++;
            }
        }
        cout << ans % 998244353 << endl;
    }
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
