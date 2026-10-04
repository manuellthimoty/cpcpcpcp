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
    vector<double> c(n),p(n);
    for(int i = 0 ; i < n ; i++){
        cin >> c[i] >> p[i];
    } 
    vector<double> dp(n);
    dp[n-1] = c[n-1];
    for(int i = n - 2; i >= 0 ; i --){
        dp[i] = max(dp[i+1], c[i] + ((100.0 - p[i])/100.0) * dp[i+1]);
    }
    cout << fixed << setprecision(6) << dp[0] <<  endl;
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
