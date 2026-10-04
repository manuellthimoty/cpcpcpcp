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

// y + i (mod x + i) = (y - x) (mod x + i)
// y - x >= x + i
// i <= y - 2x

void solve(){
    ll x,y,k ; cin >> x >> y >> k;
    ll bound = max(0LL,min(y-2*x,k-1));
    ll ans = 0;
    for(int i = 0; i <= bound ; i++){
        ll cur = (y + i) % (x+i);
        ans += cur;
    }
    ans += max(0LL,(k- bound-1) * (y-x));
    cout << ans << endl;

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
