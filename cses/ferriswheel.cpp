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
   int n,x ;cin >> n >> x;
   vll p(n);
   input(p,0,n);
   sort(p.begin(),p.end());
   int ans = 1;
   int curr = 0;
   REP(i,0,n){
    if(curr > x){
        ans ++;
        curr = p[i-1];
    }
    curr += p[i];
   }
   if(curr > x) ans ++;
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
