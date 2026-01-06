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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        bool found = false;
        long long x, y;
        for (int i = 0; i < n && !found; i++) {
            for (int j = i + 1; j < n && !found; j++) {
                if ((a[j] % a[i]) % 2 == 0) {
                    found = true;
                    x = a[i];
                    y = a[j];
                }
            }
        }

        if (found) cout << x << " " << y << "\n";
        else cout << -1 << "\n";
    }
}
