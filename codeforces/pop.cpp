#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];

        vector<long long> a = x;
        sort(a.begin(), a.end());
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

        vector<long long> suff(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) suff[i] = suff[i + 1] + a[i];

        // answer for each original x[i]
        for (int i = 0; i < n; i++) {
            long long s = x[i];

            // split point: first pos where a[pos] >= s
            int pos = lower_bound(a.begin(), a.end(), s) - a.begin();
            long long left_cnt = pos;
            long long left_sum = pref[pos];
            long long left_val = 0;
            if (left_cnt > 0) {
                left_val = left_cnt * (s + 1) - left_sum;
            }

            // RIGHT PART: points >= s
            // Contribution = sum( x_j - s + 1 ) for all x_j >= s
            long long right_cnt = n - pos;
            long long right_sum = suff[pos];
            long long right_val = 0;
            if (right_cnt > 0) {
                right_val = right_sum - right_cnt * (s - 1);
            }

            long long ans = left_val + right_val;
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}
