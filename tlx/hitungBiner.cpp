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

    ll n,c; cin >> n >> c;
    vector<int> op(n+1);
    for(int i = 1 ; i <= n ; i++){
        string s; cin >> s;
        if(s == "XOR") op[i] = 0;
        else if(s == "AND") op[i] = 1;
        else op[i] = 2;
    }
    ll MOD = 1e9+7;
    vector<vector<ll>> dp(n+2,vector<ll>(3,0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n+1 ; i++){
        int opr = op[i-1];
        if(opr == 0){
            dp[i][0] = dp[i-1][1] + dp[i-1][0];
            dp[i][1] = dp[i-1][1] + dp[i-1][0];
        }
        else if(opr == 1){
            dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        }
        else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + dp[i-1][0] + dp[i-1][1];
        }
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    cout << dp[n+1][c] % MOD << endl;

    return 0;
}
