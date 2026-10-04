#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll powerMod(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll MOD = 1e9 + 7;
    const ll MOD_EXP = MOD - 1;

    ll totalSum = 1;
    ll totalCount_mod = 1;   // buat output
    ll totalCount_exp = 1;   // buat eksponen
    ll totalProduct = 1;

    ll t; 
    cin >> t;

    vector<pair<ll,ll>> factors;

    while(t--){
        ll x, k;
        cin >> x >> k;
        factors.push_back({x, k});

        ll numerator = (powerMod(x, k + 1, MOD) - 1 + MOD) % MOD;
        ll inv = powerMod(x - 1, MOD - 2, MOD);
        totalSum = totalSum * numerator % MOD * inv % MOD;

        totalCount_mod = totalCount_mod * (k + 1) % MOD;
        totalCount_exp = totalCount_exp * (k + 1) % MOD_EXP;
    }

    for(auto [x, k] : factors){
        ll exp = (k % MOD_EXP) * (totalCount_exp / 2) % MOD_EXP;
        totalProduct = totalProduct * powerMod(x, exp, MOD) % MOD;
    }

    cout << totalCount_mod << " " << totalSum << " " << totalProduct << "\n";
    return 0;
}
