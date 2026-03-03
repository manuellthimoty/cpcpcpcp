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
    int n ; cin >> n; int q ; cin >> q;
    vint a(n); input(a,0,n);
    vll prefsum(n); vll prefcnt1(n);
    prefsum[0] = a[0];
    if(a[0] == 1) prefcnt1[0] = 1;
    else prefcnt1[0] = 0;
    for(int i = 0 ; i < n ; i++){
        prefsum[i] = prefsum[i-1] + a[i];
        prefcnt1[i] = prefcnt1[i-1];
        if(a[i] == 1) prefcnt1[i]++;
    }
    while(q--){
        int l,r ; cin >> l >> r;
        l--; r--;
        if(l == r){
            cout << "NO" << endl;
            continue;
        }
        ll cursum = prefsum[r] - prefsum[l-1];
        int curlen = r - l + 1;
        int cur1 = prefcnt1[r] - prefcnt1[l-1];
        int cur2 = curlen - cur1;
        int curminsum = cur1 * 2 + cur2 ;
        if(curminsum > cursum) cout << "NO" << endl;
        else cout << "YES" << endl;
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
