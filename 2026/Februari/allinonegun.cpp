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
    ll n,h,k ; cin >> n >> h >> k;
    vll a(n);
    REPLL(i,0,n){
        cin >> a[i];
    }
    vll pref(n);
    pref[0] = a[0];
    for(ll i = 1 ; i < n ; i++){
        pref[i] = pref[i-1] + a[i]; 
    }
    ll sum = pref[n-1];
    if( h % sum == 0){
        ll cycle = h/sum;
        cout << cycle * n + (cycle-1) * k << endl;
        return;
    }
    ll score = (h/sum) * (n+k);
    ll sisa = h % sum;
    vll mn(n);
    vll mx(n);
    mn[0] = a[0];
    for(ll i = 1; i < n ; i++){
        mn[i] = min(mn[i-1],a[i]);
    }
    mx[n-1] = a[n-1];
    for(ll i = n-2 ; i >= 0 ; i--){
        mx[i] = max(mx[i+1],a[i]);
    }
    for(ll i = 0 ; i < n ; i++){
        ll curr = pref[i];
        if(i < n-1){
            curr = max(curr,pref[i] + mx[i+1] - mn[i]);
        }
        
        if(curr >= sisa){
            score += i+1;
            break;
        }
    }
    cout << score << endl;
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

