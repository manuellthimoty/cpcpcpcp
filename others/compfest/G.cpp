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
int n; int k;
const int INF = 1e9;
vector<int> a(n+1);
struct FenwickTreeMx {
    vector<int> bit;
    int n;

    FenwickTreeMx(int n) {
        this->n = n;
        bit.assign(n, -INF);
    }

    FenwickTreeMx(vector<int> a) : FenwickTreeMx(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmax(int r) {
        int ret = -INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};



bool check(int k){
    vector<int> newA(n+1);
    for(int i = 1 ; i <= n ; i++){
        if(a[i] >= k) newA[i] = 1;
        else newA[i] = -1;
    }   
    vector<ll> pref(n+1);
    pref[1] = a[1];
    for(int i = 2; i <= n ; i++){
        pref[i] = pref[i-1] + a[i];
    }

    int offset = n+2;
    int sz = 2 * n + 5;
    FenwickTreeMx few(sz);

    vector<int> dp(n+1,-INF);
    dp[0] = 0;

    for(int i = 3 ; i <= n ; i++){
        int j = i-3;
        if(dp[j] != -INF){
            few.update(pref[j] + offset,dp[j]);
        }
        int mxDp = few.getmax(pref[i]-1 + offset);

        if(mxDp != -INF){
            dp[i] = mxDp + 1;
        }
    }
    return dp[n] >= k;
    
}

int main() {
    GK();

    // int t;
    // cin >> t;

    cin >> n >> k;
    for(int i = 1; i <= n ; i++) cin >> a[i];

    int low = 0;
    int high = 1e9+1;
    
    int ans = -1;
    while(low <= high){
        int mid = low + (high- low)/2;
        if(check(mid)){
            ans = mid;
            low = mid+1;

        }
        else high = mid-1;

    }
    cout << ans << endl;

    return 0;
}
