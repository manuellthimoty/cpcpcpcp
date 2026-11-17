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

// dp[i][j] = dp[i-j][j-1] + a[i] = dp[i-2*j+1][j-2] + a[i] + a[i-j] = dp[
// dp[i][j] = dp[i-kj + (k)*(k-1)/2][j-k] + a[i] + a[i-j] +.. + a[]
void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    ll curr = k;
    ll ans = k;
    for(int start = 1 ; start <= n ; start++){
        int curidx = start;
        ll curans = curr;
        int game = 1;
        while(curidx <= n){
            if(curans + a[curidx] < 0){
                break;
            }
            curans = (ll)curans + (ll) a[curidx];
            ans = max(ans,curans);
            curidx += game;
            game++;
        }
        ans = max((ll)ans,(ll)curans);
    }
    cout << ans << endl;
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
