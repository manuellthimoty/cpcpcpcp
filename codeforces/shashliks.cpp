#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll k,a,b,x,y ; cin >> k >> a >> b >> x >> y;
    ll first = max(0LL,(k-a)/x);
    ll remainder = k - first*x;
    if(remainder >= a){
        first++;
        remainder -= x;
    }
    ll second = 0;
    if(remainder >= b){
        second = max(0LL,(remainder - b)/y);
    }
    remainder = remainder - second*y;
    if(remainder >= b){
        remainder -= y;
        second++;
    }
    ll ans = first + second;

    second = max(0LL,(k-b)/y);
    remainder = k - second*y;
    if(remainder >= b){
        remainder -= y;
        second++;
    }
    first = 0;
    if(remainder >= a){
        first = max(0LL,(remainder - a)/x);
    }
    remainder = remainder - first * x;
    if(remainder >= a){
        first ++;
        remainder -= x;
    }
    ans = max(ans,first+second);
    cout << ans << endl;
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