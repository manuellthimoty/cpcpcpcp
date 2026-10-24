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
    int n ; cin >> n;
    ll f; cin >> f;

    vector<vector<ll>> dp(n,vector<ll>(n,0));
    vector<ll> ans(n,0);
    vector<ll> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    vector<vector<ll>> st(n,vector<ll>(15));

    for(int i = 0 ; i < n ; i++){
        st[i][0] = a[i];
    }

    for(int j = 1; (1 << j) <= n ; j++){
        for(int i = 0 ; (i + (1 << j) -1) < n ; i++){
            st[i][j] = min(st[i][j-1], st[i+(1 << (j-1))][j-1]);
        }
    }

    auto querymn = [&] (int l, int r){
        int len = r-l+1;
        int k = __lg(len);
        return min(st[l][k], st[r-(1<<k) + 1][k]);
    };

    dp[0][1] = 1 * a[0] - f;
    ans[0] = dp[0][1];
    for(int i = 1; i < n ; i++){
        ans[i] = (i+1) * querymn(0,i) - f;
        for(int j = 1 ; j <= i; j++){
            dp[i][j] = ans[i-j] + j * querymn(i-j+1,i) -f;
            ans[i] = max(ans[i],dp[i][j]);
        } 
    }
    cout << ans[n-1];

    return 0;
}
