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
    int n ; cin >> n;
    vint a(n+1); input(a,1,n+1);
    for(int i = n/2-1 ; i >= 1 ; i--){
        if(a[i] == a[i+1] || a[n-i+1] == a[n-i]){
            swap(a[i],a[n-i+1]);
        }
    }
    int ans = 0;
    for(int i = 1 ; i < n ; i++) ans += (a[i] == a[i+1]);
    cout << ans << endl;
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
