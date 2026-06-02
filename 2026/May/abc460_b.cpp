#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

void solve(){
    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
    ll d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    ll min_dist = (r1-r2) * (r1-r2);
    ll max_dist = (r1+r2) * (r1+r2);
    
    if(min_dist <= d && d <= max_dist) {
        YES
    } else {
        NO
    }
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
