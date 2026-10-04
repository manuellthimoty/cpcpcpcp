#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

void solve(){
    ll x,y; cin >> x >> y;
    if((x - 2 * y) % 3 == 0 && ((x - 2 * y)/3) >= 0 && x >=0
    && (x + 4 * y) % 3 == 0 && ((x + 4 * y)/3 >= 0)        
) YES;
    else NO;
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
