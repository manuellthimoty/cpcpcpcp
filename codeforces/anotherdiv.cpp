#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tens(10);
vector<ll> possible;
vector<vector<ll>> factsof10(10);
ll coundig(ll n){
    ll c = 0;
    while(n > 0){
        c ++;
        n /= 10;
    }
    return c;
}

void solve(){
    ll x ; cin >> x;
    vector<ll> factofx;
    for(ll i = 1; i * i <= x; i++){
        if( x % i == 0){
            factofx.push_back(i);
            if( x / i != i){
                factofx.push_back(x/i);
            }
        }
    }
    sort(factofx.begin(),factofx.end());
    ll ans = 0;
    bool found = false;
    for(int i = 1 ; i < 10 && !found ; i++){
        for(auto d1 : factofx){
            for(auto d2 : factsof10[i]){
                ll curfac = d1 * d2;
                ll y = curfac - x;
                if(y < 0 || y >= 1e9) continue;
                if(coundig(y) == i){
                    ans = y;
                    found = true;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    tens[0] = 1;
    tens[1] = 10;
    for(int i = 2 ; i < 10 ; i++){
        tens[i] = 10 * tens[i-1];
    }
    for(int i = 0 ; i < 10 ; i++){
        possible.push_back(tens[i] - 1);
    }
    for(int i = 0 ; i < 10 ; i++){
        ll cur = possible[i];
        for(ll j = 1; j * j <=cur ; j++){
            if(cur % j == 0){
                factsof10[i].push_back(j);
                if(cur / j != j){
                    factsof10[i].push_back(cur / j);
                }
            }
        }
        sort(factsof10[i].begin(),factsof10[i].end());
    }
    while (t--) {
        solve();
    }

    return 0;
}
