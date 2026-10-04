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
    ll a,b;
    for(ll c = 1 ; 1000*c <= 500000 ; c++){
        ll lhs = 500000 - 1000*c;
        for(ll a = 1 ; a * a <= lhs ; a++){
            if(lhs % a == 0){
                ll b = lhs/a;
                if(a * a + b * b == c * c){
                    cout << a << " " << b << " " << c << endl;
                    cout << a * b * c << endl;
                    return;
                }
            }
        }
    }
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
