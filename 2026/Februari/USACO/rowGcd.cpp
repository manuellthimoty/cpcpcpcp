#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if((a == 1) || (b==1)) return 1;
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a %b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // gcd(a1 + bj, a2 + bj) = gcd(a1+ bj, a2-a1);
    // gcd(a1+bj, a3+bj) = gcd(a1+bj,a3 - a1);
    ll n,m ; cin >> n >> m;
    vector<ll> a(n+1),b(m+1);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    for(ll i = 1 ; i <= m ; i++) cin >> b[i];
    if(n == 1){
        for(ll i = 1 ; i<= m ; i++){
            cout << b[i] + a[1] << " ";
        }
        cout << endl;
        return 0;
    }

    ll curGcd = abs(a[2] - a[1]);
    for(ll i = 3 ; i <= n ; i++){
        curGcd = gcd(curGcd,abs(a[i] - a[1]));
    }
    for(ll j = 1 ; j <= m ; j++){
        ll ans = gcd(a[1] + b[j],curGcd);
        cout << ans << ' ';
    }
    cout << endl;

    return 0;
}