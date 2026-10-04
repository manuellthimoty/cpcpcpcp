#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// bool ada(ll n, ll a, ll b ){
//     if(a == 1) return ((n-1) % b == 0);
//     if(b == 1) return true;
//     if(n == 1) return true;
//     if(n < 0) return false;
//     if(n % a != 0){
//         return ada(n - b,a,b);
//     }
//     return ada(n/a,a,b);
// }
bool ada(ll n, ll a, ll b) {
    if(a == 1) return ((n - 1) % b == 0);
    if(b == 1) return true;
    
    while(n >= 1) {
        if(n == 1) return true;
        if(n % a == 0) {
            n /= a;
        } else {
            ll remainder = n % a;
            n -= remainder
            if(n < 1) return false;
        }
    }
    return false;
}

void solve() {
    ll n,a,b; cin >> n >> a >> b;
    bool ans = ada(n,a,b);

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}