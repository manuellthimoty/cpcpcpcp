#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if (a == 1 || b == 1) return 1;
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    ll n,x, y ; cin >> n >> x >> y;
    ll g = gcd(x,y);
    ll l = (x/g) * y;
    ll cx = n/x - n/l;
    ll cy = n/y - n/l;
    ll resy = (cy * (cy+1))/2;
    ll resx = cx * n - (cx * (cx-1))/2;
    cout << resx - resy << endl;
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
