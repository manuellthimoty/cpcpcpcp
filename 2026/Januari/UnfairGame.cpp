#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;
// ll nCr(ll n, ll r) {
//     // Invalid case
//     if (r > n) return 0;  
//     // Base cases
//     if (r == 0 || n == r) return 1;    

//     double res = 0;
//     for (ll i = 0; i < r; i++) {
//         // log(n!) - log(r!) - log((n-r)!)
//         res += log(n - i) - log(i + 1);  
//     }

//     return (ll)round(exp(res));
// }

// void solve() {
//     ll n, k ; cin >> n >> k;
//     ll max_t = (ll) log2(n);
//     ll ans = 0;
//     for(ll i = 1 ; i<=max_t ; i++){
//         if(i == 1){
//             if(1 > k) ans++;
//             continue;
//         }
//         for(ll j = 1 ; j <= i ; j++){
//             if (i+j > (k+1)){
//                 ans+= nCr(i-1,j-1);
//             }
//         }
//     }
//     if(max_t +1 > k) ans++;

//     cout << ans << endl;
//     // cout << max_t << endl;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll C[35][35];
    for (int i = 0; i < 35; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    int t;
    cin >> t;

    while (t--) {
        // solve();
        ll n, k ; cin >> n >> k;
        ll max_t = (ll) log2(n);
        ll ans = 0;
        for(ll i = 1 ; i<=max_t ; i++){
            if(i == 1){
                if(1 > k) ans++;
                continue;
            }
            for(ll j = 1 ; j <= i ; j++){
                if (i+j > (k+1)){
                    ans+= C[i-1][j-1];
                }
            }
        }
        if(max_t +1 > k) ans++;

        cout << ans << endl;
        }

        return 0;
}