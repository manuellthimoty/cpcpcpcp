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

vector<vector<int>> susun(int n, int p){
    vector<vector<int>> ans(n,vector<int>(n));
    vector<vector<bool>> done(n,vector<bool>(n));
    int cur = n+1;
    for(int i = 0 ; i <= n-p-1 ; i++){
        ans[i][i] = i+1;
        done[i][i] = true;
    }
    for(int i = n-p ; i < n ; i++){
        ans[i][n-p-1] = i+1;
        done[i][n-p-1] = true;
    }
    // int cur = n+1;
    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(done[i][j]) continue;
            ans[i][j] = cur;
            cur++;
        }
    }
    return ans;
}

void solve(){
    int n,k ; cin >> n >> k;
    if( k < n  || k == ( 2 * n)){
        cout << -1 << endl;
        return;
    }
    int p = k - n;
    vector<vector<int>> res = susun(n,p);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
