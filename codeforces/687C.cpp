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


int main() {
    GK();

    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(k+1,vector<bool>(501,false)));
    dp[0][0][0] = true;
    
    for(int i = 1; i <= n ; i++){
        for(int j = 0 ; j <= k ; j++){
            for(int m = 0 ; m <= 500 ; m++){
                dp[i][j][m] = dp[i-1][j][m];
                if (j >= a[i]) {
                    if (dp[i - 1][j - a[i]][m])  dp[i][j][m] = true;
                    if (m >= a[i] && dp[i - 1][j - a[i]][m - a[i]]) dp[i][j][m] = true;
                }

            }
        }
    }
    vector<int> ans;
    for(int m = 0 ;m <= 500 ; m++){
        if(dp[n][k][m]) ans.push_back(m);
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";

    return 0;
}
