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

void solve(int n){
    vector<int> d(n+1);
    for(int i = 1; i <= n ; i++) cin >> d[i];
    vector<int> mnleft(n+1), mnright(n+1);
    mnleft[1] = d[1];
    for(int i = 2; i <= n ; i++) mnleft[i] = min(mnleft[i-1],d[i]);
    mnright[n] = d[n];
    for(int i = n-1 ; i >= 1 ; i--) mnright[i] = min(mnright[i+1],d[i]);
    ll ans = 0;
    for(int i = 1; i <= n ; i++) ans += d[i] - max(mnleft[i],mnright[i]);
    cout << ans << endl;
}
int main() {
    GK();

    while (true) {
        int n ; cin >> n;
        if(n == 0) break;
        solve(n);
    }

    return 0;
}
