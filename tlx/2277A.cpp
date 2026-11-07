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

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ;i < n ; i++) cin >> a[i];
    vector<int> f(n+1,0);
    for(auto x : a) f[x]++;
    int ans = 0;
    int target = 0;
    int acc = 0;
    // for(auto x : a) cout << f[x] << " ";
    while(target <= n){
        if(target <= n && f[target] == 0) break;
        acc += f[target];
        f[target]--;
        acc--;
        if(acc >= k-1){
            acc -= (k-1);
            target++;
            // cout <<"HERE";
        }
        else break;
    }
    cout << target << endl;

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
