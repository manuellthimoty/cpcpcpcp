#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> b(n);
        long long S = 0;
        int m = 0;

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            S += b[i];
            if (b[i] != 0) m++;
        }

        long long ans = min( (long long)m, S - n + 1 );
        if (ans < 0) ans = 0;   // penjagaan ekstra

        cout << ans << "\n";
    }

    return 0;
}
