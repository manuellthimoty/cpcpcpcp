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
    int r,c,n; cin >> r >> c >> n ;
    vector<vector<int>> color(r+1,vector<int> (c+1,0));
    while(n--){
        int x,y ; cin >> x >> y;
        for(int j = 1 ; j <= c ; j++) color[x][j] = (color[x][j] + 1 ) % 2;
        for(int i = 1 ; i <= r ; i++){
            if(i == x) continue;
            color[i][y] = (color[i][y] + 1) % 2;
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= r; i++){
        for(int j = 1 ; j <= c ; j++){
            if(color[i][j] == 1) ans ++;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
