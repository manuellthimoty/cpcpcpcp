#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)


void solve(){

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> f(m + 1, 0);
    for(auto x : a) f[x]++;

    vector<ll> suff(m + 2, 0);

    for(int i = m; i >= 0; i--){
        suff[i] = suff[i + 1] + f[i];
    }
    ll sum = 0;
    for(auto x : a) sum += x;
    vector<ll> ans(m + 1, 0);
    ll P = 1;

    for(int k = 1; k <= m; k++){
        P *= 2;
        if(P > m){
            ans[k] = sum;
            for(int i = k + 1; i <= m; i++){
                ans[i] = sum;
    

            break;
        }

        ll best = 0;
        for(int x = 1; P * x <= m; x++){

            ll cur = 0;
            for(ll j = 1; j < P; j++){
                cur += suff[j * x];
            }
            cur += f[P * x];
            best = max(best, cur);
        }

        ans[k] = best;
    }

    for(int k = 1; k <= m; k++){
        cout << ans[k] << " ";
    }
    cout << '\n';
}

int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
