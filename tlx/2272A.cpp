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
    int n ; cin >> n;
    int k; cin >> k;
    
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    if(k == 1){
        cout << -1 << endl;
        return;
    }
    vector<int> idx(n+1);
    for(int i =1 ; i <= n ; i++) idx[a[i]] = i;
    int mx = a[1];
    for(int i = 2 ; i <= n-k+1 ; i++) mx = max(mx,a[i]);
    int mn = a[n];
    for(int i = n-1 ; i >= n-k+2 ; i--) mn = min(mn,a[i]);
    if(mx > mn){
        cout << idx[mx] << " " << idx[mn] << endl;
    }
    else cout << -1 << endl;

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
