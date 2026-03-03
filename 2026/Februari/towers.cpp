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
vector<vector<ll>> dp;

int M = 1e9 + 7;
void start(){
    int n = 1e6;
    dp.resize(n+1,vector<ll> (2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 5;
    dp[2][1] = 3;
    for(int k = 3 ; k <= n ; k++){
        dp[k][0] = ((4 * dp[k-1][0]) % M + dp[k-1][1] % M ) % M;
        dp[k][1] = (dp[k-1][0] % M + (2 * dp[k-1][1]) % M) % M ;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    start();
    while (t--) {
        int k ; cin >> k;
        cout << (dp[k][0] + dp[k][1]) % M << endl;
    }

    return 0;
}
