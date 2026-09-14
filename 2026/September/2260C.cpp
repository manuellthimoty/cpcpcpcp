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

void solve(){
    ll x,y; cin >> x >> y;
    ll ans = x+y;
    ll a= 0;
    bool less = false;
    for(int i = 30 ; i >= 0 ; i--){
        bool X = ( x>> i) & 1;
        bool B = (ans >> i) & 1;
        if(!less){
            if(X == 0){

            }
            else if(B == 1){
                a |= (1LL << i);
            }
            else{
                less = true;
            }
        }
        else{
            if(B) a|= (1LL << i);
        }
    }
    ll steps = x-a;
    cout << ans << " " << steps << endl;
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
