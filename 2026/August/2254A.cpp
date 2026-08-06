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
    vector<int> t(3);
    cin >> t[0] >> t[1] >> t[2];
    int ans = 0;    
    while (t[0] != t[1] && t[1] != t[2] && t[0] != t[2]) {
        sort(t.begin(), t.end());
        t[0]++;
        t[2]--;
        ans++;
    }
    
    cout << ans << "\n";
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
