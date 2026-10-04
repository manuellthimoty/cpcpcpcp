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
    vector<int> a(7);
    for(int i = 0 ; i < 7 ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 0 ; i < 6 ; i++){
        a[i] = a[i] * -1;
    }
    int ans = 0;
    for(int i = 0 ; i < 7 ; i++) ans += a[i];
    cout << ans << endl;
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
