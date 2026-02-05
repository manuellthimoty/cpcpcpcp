#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll m; cin >> m;
    ll count = 0;
    ll sisa = m;
    while(sisa > 2){
        count += sisa/3;
        ll a = sisa/3;
        ll b = a;
        ll c = sisa - (a+b);
        sisa = c;
        // cout << sisa << " ";
    }
    cout << count << endl;
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