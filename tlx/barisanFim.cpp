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


//dp[i][j] = banyaknya barisan fimoracci yg berakhir di i dan memiliki tepat j anggota

void solve(){
    int n,k ; cin >> n >> k;
    vector<int> a(n+1); 
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    // dp[i][j] 
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
