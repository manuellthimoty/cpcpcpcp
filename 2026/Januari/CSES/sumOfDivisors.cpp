#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    ll ans = 0;
    for(ll i = 1 ; i*i <= n ; i++){
        if(n % i == 0){
            ll pair = n/i;
            ans += i;
            if(pair != i){
                ans+= pair;
            }
        }
    }
    cout << ans << endl;
    

    return 0;
}