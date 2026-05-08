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
    string s; cin >> s;
    ll mx = 1;
    int n = s.size();
    for(int i = 0 ; i <= n-13 ; i++){
        ll prod = 1;
        for(int j = i ; j <= i+12 ; j++){
            prod *= (s[j] - '0');
        }
        mx = max(mx,prod);
    }
    cout << mx << endl;
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
