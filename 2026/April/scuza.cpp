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
    ll n,q ; cin >> n >> q;
    vll a(n);
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    vll prefmax(n),prefsum(n);
    prefmax[0] = a[0]; prefsum[0] = a[0];
    for(ll i = 1 ; i < n ; i++) prefmax[i] = max(prefmax[i-1],a[i]);
    for(ll i = 1 ; i < n ; i++) prefsum[i] = prefsum[i-1] + a[i];

    while(q--){
        ll legs ; cin >> legs;
        if(legs < a[0]){
            cout << 0 << " ";
            continue;
        }
        if(legs > prefmax[n-1]){
            cout << prefsum[n-1] << " ";
            continue;
        }

        ll low = 0;
        ll high = n-1;
        ll maxpos = 0;
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(legs >= prefmax[mid]){
                low = mid + 1;
                maxpos = max(maxpos,mid);
            }
            else high = mid-1;
        }
        cout << prefsum[maxpos] << " ";
    }
    cout << endl;
    
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
