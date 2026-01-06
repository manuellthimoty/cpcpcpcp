    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;

        while (t--) {
            ll n;
            cin >> n;

            vector<ll> s(n + 1);  // make it 1-indexed
            for (ll i = 1; i <= n; i++) {
                cin >> s[i];
            }

            vector<ll> dp(n + 1, 1);  // dp[1..n], initialized to 1

            for (ll i = 1; i <= n; i++) {
                for (ll j = 1; j*j <= i; j++) {
                    if(i%j == 0){
                        ll j1 = j;
                        ll j2 = i/j;
                        if(s[j1]<s[i]) dp[i]=max(dp[i],dp[j1]+1);
                        if(s[j2]<s[i]) dp[i]=max(dp[i],dp[j2]+1);
                    }

                }
            }

            cout << *max_element(dp.begin() + 1, dp.end()) << "\n";
        }
    }
