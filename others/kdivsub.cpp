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
    vector<ll> pref(n+1,0);
    for(int i = 1; i <= n ; i++){
        pref[i] = pref[i-1] + a[i];
        pref[i] %= k;
    }
    vector<int> dp(n+1,0);
    unordered_map<int, int> mx;
    mx[0] = 0;
    // dp[i] = max(dp[i-1], dp[j-1] + 1), dimana a[i] = a[j]
    // mx[k] = max(dp[j-1]), dimana a[j] = k
    for(int i = 1; i <= n ; i++){
        int r = pref[i];
        dp[i] = dp[i-1];
        if (mx.count(r)) {
            dp[i] = max(dp[i], mx[r] + 1);
        }

        // if(i+1 <= n){
        //     int nxt = pref[i+1];
        //     mx[nxt] = max(mx[nxt],dp[i]);
        // }
        mx[r] = max(mx[r], dp[i]);

    }
    cout << dp[n];

    return 0;
}
