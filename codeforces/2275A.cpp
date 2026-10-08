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
// (x0 -x) ^2 + (y0 -y)^2 = R^2
// 

bool is_squared(ll n){
    return ((int) sqrt(n) * (int) sqrt(n)) == n;
}
void solve(){
    ll x0,y0,R; cin >> x0 >> y0 >> R;
    for(ll x = -35 ; x <= 35 ; x++){
        ll first = x0 - x;
        ll y_squared = R * R - first * first;
        if(is_squared(y_squared)){
            ll y = y0 - sqrt(y_squared);
            cout << x << " " << y << endl;
            return;
        }
    }
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
