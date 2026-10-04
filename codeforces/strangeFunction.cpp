#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 MOD = 1e9 + 7;

int64 lcm_safe(int64 a, int64 b) {
    if (a > (long double)1e16 / b) return (int64)1e16 + 1;
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int64> L;
    L.push_back(1); 

    for (int k = 1; k <= 50; k++) {
        int64 next = lcm_safe(L.back(), k);
        L.push_back(next);
        if (next > (int64)1e16) break;
    }

    int t;
    cin >> t;
    while (t--) {
        int64 n;
        cin >> n;

        int64 ans = 0;
        for (int k = 1; k < (int)L.size(); k++) {
            int64 a = L[k - 1];
            int64 b = L[k];
            if (a > n) break;

            int64 cnt = n / a - n / b;
            ans = (ans + (cnt % MOD) * k) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}
