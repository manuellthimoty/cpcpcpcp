#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;

        sort(a.begin(), a.end());

        unordered_map<ll,ll> freq;
        for (ll x : a) freq[x]++;

        vector<ll> vals;
        ll totalPairs = 0;
        for (auto &p: freq) {
            ll x=p.first, f=p.second;
            ll pairs = f/2;
            if (pairs>0) vals.push_back(x);
            totalPairs += x * pairs;
        }

        ll ans = 0;

        // Case 1: Even number of sides
        if (!vals.empty()) {
            ll maxSide = *max_element(vals.begin(), vals.end());
            ll P = 2 * totalPairs;
            if (P > 2*maxSide) ans = max(ans, P);
        }

        // Case 2: Odd number with center side s
        for (auto &p : freq) {
            ll s = p.first;
            if (p.second >= 1) {
                ll P = 2 * totalPairs + s;
                ll maxSide = max(s, (vals.empty() ? 0LL : *max_element(vals.begin(), vals.end())));
                if (P > 2 * maxSide)
                    ans = max(ans, P);
            }
        }

        cout << ans << "\n";
    }
}
