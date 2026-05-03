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
    ll n,k ; cin >> n >> k; vll a(n);
    ll tot = 0;
    REP(i,0,n) {cin >> a[i]; tot +=a[i];}

    ll low = 0;
    for(ll x : a) low = max(low, x);
    ll high = tot;
    ll ans = tot;
    while(low <= high){
        ll curcek = low + (high-low)/2;
        
        ll cursum = 0;
        ll kelompok = 1;
        
        for(int i = 0 ; i < n ; i++){
            if(cursum + a[i] > curcek){
                kelompok++;
                cursum = a[i];
            } else {
                cursum += a[i];
            }
        }
        
        if(kelompok <= k){
            ans = curcek;
            high = curcek-1;
        }
        else{
            low = curcek+1;
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
