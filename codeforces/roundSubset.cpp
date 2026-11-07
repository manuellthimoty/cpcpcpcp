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

ll computeV(ll nums, ll fac){
    ll cnt = 0 ;
    while(nums % fac == 0){
        cnt++;
        nums/=fac;
    }
    return cnt;
}


int main() {
    GK();

    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<pair<int,int>> b(n+1);
    for(int i =1 ; i <= n ; i++){
        b[i] = {computeV(a[i],2),computeV(a[i],5)};
    }

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(3)));
    for(int i =1 ; i <= n ; i++){
        for(int j = 0; j <= k ; j++){
            // ga diambil
            dp[i][j][0] = dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j][1];
            dp[i][j][2] = dp[i-1][j][2];
            for(int m = 0 ; m <= i-1; m++){
                // diambil
                int curMin = dp[m][j-1][0];
                int curx = dp[m][j-1][1];
                int cury = dp[m][j-1][2];

                int newx = curx + b[i].first;
                int newy = cury + b[i].second;
                int newMin = min(newx,newy);
                if(newMin > dp[i][j][0]){
                    dp[i][j][0] = newMin;
                    dp[i][j][1] = newx;
                    dp[i][j][2] = newy;
                }
            }
        }
    }
    cout << dp[n][k][0];
    return 0;
}
