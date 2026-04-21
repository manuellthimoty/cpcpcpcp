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

void solve(){
    ll p,q ; cin >> p >> q;
    ll tot = p + 2*q;
    ll rhs = 2 * (tot) + 1;
    // tinjau juga bahwa jika ukurannya m x n, q harus q <= min(m*(n+1), n*(m+1))
    for(ll i = 1; i * i <= rhs ; i++){
        if(rhs % i != 0) continue;
        ll A = i;
        ll B = rhs/i;

        if(A % 2 != 1 | B % 2 != 1) continue;
        ll m = (A-1)/2; ll n = (B-1)/2;
        if(m <= 0 || n <= 0) continue;
        if(q <= min(m*(n+1),n*(m+1))){
            cout << m << " " << n << endl;
            return;
        }
        m = (B-1)/2; n = (A-1)/2;
        if(m <= 0 || n <= 0) continue;

        if(q <= min(m*(n+1),n*(m+1))){
            cout << m << " " << n << endl;
            return;
        }
    }
    cout << -1 << endl;
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
