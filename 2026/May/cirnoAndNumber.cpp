#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> al[10][10];

void precompute() {
    for (ll d1 = 0; d1 <= 8; d1++) {
        for (ll d2 = d1 + 1; d2 <= 9; d2++) {
            
            vector<ll>& res = al[d1][d2];
            res.reserve(600000); 

            queue<ll> q;

            if (d1 == 0) {
                res.push_back(0); 
            } else {
                res.push_back(d1);
                q.push(d1);
            }

            if (d2 > 0) {
                res.push_back(d2);
                q.push(d2);
            }

            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                if (u > 1e17) continue;

                ll n1 = u * 10 + d1;
                ll n2 = u * 10 + d2;

                res.push_back(n1);
                q.push(n1);

                res.push_back(n2);
                q.push(n2);
            }
        }
    }
}

void solve() {
    ll a, n; 
    cin >> a >> n;
    ll d1, d2; 
    cin >> d1 >> d2;
    
    // if (d1 > d2) swap(d1, d2);
    
    const vector<ll>& results = al[d1][d2];
    
    ll ans = 2e18;
    auto it = lower_bound(results.begin(), results.end(), a);

    if (it != results.end()) {
        ans = min(ans, abs(a - *it));
    }
    if (it != results.begin()) {
        ans = min(ans, abs(a - *(it - 1)));
    }
    
    cout << ans << endl;
}

int main() {
    // Optimasi I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}