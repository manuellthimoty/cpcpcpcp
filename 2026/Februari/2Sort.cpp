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
    int n ; cin >> n; int k ; cin >> k;
    vint a(n); input(a,0,n);
    vint cnt(n);
    cnt[n-1] = 1;
    for(int i = n-2 ; i>= 0 ; i--){
        if(a[i] < 2 * a[i+1]) cnt[i] = cnt[i+1] + 1;
        else cnt[i] = 1;
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(cnt[i] >= k+1) ans++;
    }
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
