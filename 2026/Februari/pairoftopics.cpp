#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> diff(n);
    for(int i = 0; i < n; i++) diff[i] = a[i] - b[i];

    sort(diff.begin(), diff.end());

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        // Cari j > i sehingga diff[i] + diff[j] > 0
        int idx = upper_bound(diff.begin() + i + 1, diff.end(), -diff[i]) - diff.begin();
        ans += n - idx;
    }
    cout << ans << endl;
    return 0;
}