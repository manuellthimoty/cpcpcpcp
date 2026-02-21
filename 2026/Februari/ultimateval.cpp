#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n ; cin >> n;
    
    vector<ll> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    
    vector<ll> pref1max(n+2, -1e18);
    vector<ll> suff1max(n+2, -1e18);
    vector<ll> pref2min(n+2, 1e18);
    vector<ll> suff2max(n+2, -1e18);
    
    ll curscore = 0; // Diganti ke ll
    for(int i =1 ; i <= n ; i++){
        if(i % 2 == 1){
            curscore += a[i];
        }
        else curscore -= a[i];
    }
    
    pref2min[1] = 2LL * a[1] + 1;
    
    if (n >= 2) {
        pref1max[2] = 2LL * a[2] - 2;
        pref2min[2] = pref2min[1];
    }
    
    for(int i = 3 ; i <= n ; i++){
        if( i % 2 == 0){
            pref1max[i] = max(pref1max[i-1], 2LL * a[i] - i);
            pref2min[i] = pref2min[i-1];
        }
        else{
            pref2min[i] = min(pref2min[i-1] , 2LL * a[i] + i);
            pref1max[i] = pref1max[i-1];
        }
    }
    
    int pojok2 = n;
    if(pojok2 % 2 == 1) pojok2 --;
    
    if (pojok2 >= 2) suff2max[pojok2] = 2LL * a[pojok2] + pojok2;
    
    int pojok = n;
    if(pojok % 2 == 0) pojok --;
    if (pojok >= 1) suff1max[pojok] = pojok - 2LL * a[pojok];
    
    for(int i = n-1 ; i >=1 ; i--){
        if(i % 2 == 1){
            suff1max[i] = max(suff1max[i+1], i - 2LL * a[i]);
            suff2max[i] = suff2max[i+1];
        }
        else{
            suff2max[i] = max(suff2max[i+1], 2LL * a[i] + i);
            suff1max[i] = suff1max[i+1];
        }
    }
    
    ll max1 = -1e18; 
    ll max2 = -1e18;
    for(int i = 1; i <= n-1 ; i++){
        max1 = max(max1, pref1max[i] + suff1max[i+1]);
        max2 = max(max2, suff2max[i+1] - pref2min[i]);
    }
    
    ll max_same = 0;
    if (n >= 3) {
        ll last_odd = (n % 2 != 0) ? n : n - 1;
        ll last_even = (n % 2 == 0) ? n : n - 1;
        
        if (last_odd >= 3) max_same = max(max_same, last_odd - 1);
        if (last_even >= 4) max_same = max(max_same, last_even - 2);
    }
    
    ll ans = curscore + max({0LL, max1, max2, max_same});
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