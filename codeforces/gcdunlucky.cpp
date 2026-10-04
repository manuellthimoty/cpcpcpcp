    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void solve() {
        int n;
        cin >> n;

        vector<ll> p(n), s(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> s[i];

        if (n == 1) {
            cout << (p[0] == s[0] ? "YES"  : "NO") << endl;
            return;
        }

        for (int i = 1; i < n; i++) {
            if (p[i-1] % p[i] != 0) {
                cout << "NO" << endl;
                return;
            }
            if (s[i] % s[i-1] != 0) {
                cout << "NO" << endl;
                return;
            }
        }

        if (p[n-1] != s[0]) {
            cout << "NO" << endl;
            return;
        }

        ll g = p[n-1];
        vector<ll> P(n), S(n);
        for (int i = 0; i < n; i++) {
            P[i] = p[i] / g;
            S[i] = s[i] / g;
        }

        for (int i = 1; i < n; i++) {
            ll x = P[i-1] / P[i];
            if (gcd(x, S[i]) != 1) {
                cout << "NO" << endl;
                return;
            }
        }

        for (int i = n-2; i >= 0; i--) {
            ll y = S[i+1] / S[i];
            if (gcd(y, P[i]) != 1) {
                cout << "NO" <<endl;
                return;
            }
        }

        cout << "YES" << endl;
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) solve();
        return 0;
    }
