#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n ; cin >> n;
    vector<ll> a(n+1,0),b(n+1,0);// b sorted
    
    for(ll i = 1 ; i <= n ; i++ ){
        cin >> a[i];
        b[i] = a[i];
    }
    ll maxVal = a[1];
    ll minVal = a[1];
    for(ll i = 2 ; i<= n ; i++){
        maxVal = max(maxVal,a[i]);
        minVal = min(minVal,a[i]);
    }
    sort(b.begin()+1,b.end());
    bool terurut = true;
    for(ll i = 1 ; i < n ; i ++){
        if(a[i] != b[i]){
            terurut = false;
        }
    }
    if(terurut){
        cout << -1 << endl;
        return;
    }
    ll left = 0;
    ll right = 1e9+1;
    ll ans = -1;
    
    while(left <= right){
        bool aman = true;
        ll mid = (left + right)/2;
        for(ll i = 1 ; i<= n ; i++){
            if(abs(a[i] - minVal) < mid && abs(a[i] - maxVal) < mid){
                if(a[i] != b[i]){
                    aman = false;
                    break;
                }
            }
        }
        if(aman){
            ans = max(ans,mid);
            left = mid+1;
        }
        else{
            right= mid - 1;
        }
        
    }
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