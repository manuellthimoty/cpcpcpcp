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
    int n ,m; cin >> n >> m;
    
    vector<vector<int>> a(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    if((m + n-1 )% 2 != 0){
        cout << "NO" << endl;
        return;
    }
    vector<vector<int>> dp_min(n,vector<int>(m,0)),dp_max(n,vector<int>(m,0));
    if(a[0][0] == 1){
        dp_max[0][0] = 1;
        dp_min[0][0] = 1;
    }
    for(int i = 1 ; i < n ; i++){
        dp_min[i][0] = dp_min[i-1][0] + (a[i][0] == 1);
        dp_max[i][0] = dp_max[i-1][0] + (a[i][0] == 1);
    }

    for(int i = 1 ; i < m ; i++){
        dp_min[0][i] = dp_min[0][i-1] + (a[0][i] == 1);
        dp_max[0][i] = dp_max[0][i-1] + (a[0][i] == 1);
    }
    for(int i = 1 ; i <n ; i++){
        for(int j = 1 ; j < m ; j++){
            dp_min[i][j] = min(dp_min[i][j-1],dp_min[i-1][j]) + (a[i][j] == 1);
            dp_max[i][j] = max(dp_max[i][j-1],dp_max[i-1][j]) + (a[i][j] == 1);
        }
    }
    int target = (m+n-1)/2;
    if(dp_min[n-1][m-1] <= target && target <= dp_max[n-1][m-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
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
