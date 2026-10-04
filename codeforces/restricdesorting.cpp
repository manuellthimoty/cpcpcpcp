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
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());

        long long min_wrong = LLONG_MAX;
        long long max_wrong = LLONG_MIN;

        bool already_sorted = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                already_sorted = false;
                min_wrong = min(min_wrong, a[i]);
                max_wrong = max(max_wrong, a[i]);
            }
        }

        if (already_sorted) {
            cout << -1 << "\n";
        } else {
            long long min_a = *min_element(a.begin(), a.end());
            long long max_a = *max_element(a.begin(), a.end());

            long long k = max(max_a - min_wrong, max_wrong - min_a);
            cout << k << "\n";
        }
    }
    return 0;
}
