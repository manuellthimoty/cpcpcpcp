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

ll gcd(ll a, ll b){
    if( a == 0 ) return b;
    if( b == 0 ) return a;
    return gcd(b, a % b);
}

void solve(){
    // misalkan gcd(a,b) = d, maka a = dx, b = dy, dengan gcd(x,y) = 1;
    // dx * dy = d * kpk(a,b) -> kpk(a,b) = dxy
    // maka, kpk(a,b) = gcd(a,b) * x * y, den
    ll kpk; ll fpb; cin >> fpb >> kpk;
    if(kpk % fpb != 0){
        cout << - 1<< " " << -1 << endl;
        return;
    }
    ll rhs = kpk/fpb;
    // cout << rhs << endl;
    // xy = rhs
    ll ans = 1e12;
    ll minjumlah = 1e13;
    ll mnx = 1;
    ll mny = rhs;
    for(ll i = 1; i * i <= rhs ; i++){
        if(rhs % i == 0){
            ll x = i;
            ll y = rhs/i;

            ll curjumlah = x + y;
            if(curjumlah < minjumlah && gcd(x,y) == 1){
                minjumlah = curjumlah;
                mnx = x;
                mny = y;
            }
        }
    }
    cout << fpb * mnx << " " << fpb * mny << endl;




}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
