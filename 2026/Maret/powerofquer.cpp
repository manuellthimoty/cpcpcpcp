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
    int n ; cin >> n;
    vint a(n);
    input(a,0,n);
    int INF = 1e9;
    vint ans(n+1,1e9);
    ans[0] = 0;
    vector<bool> oks(n);
    for(int i = 0 ; i < n ; i++){
        if(a[i] >= 1 && a[i] <= n){
            ans[a[i]] = 1;
            oks[a[i]] = true;
        }
    }
    for(int i = 1 ; i*i <= n ; i++){
        for(int p = 1 ; i * p <= n ; p++){
            if(oks[i*p]) continue;
            ans[i * p] = min(ans[i * p], ans[i] + ans[p]);
        }
    }
    for(int i = 1; i <= n ; i++) if(ans[i] == INF) ans[i] = -1;
    for(int i = 1; i <= n ; i++) cout << ans[i] << " ";
    cout << endl;
    
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
