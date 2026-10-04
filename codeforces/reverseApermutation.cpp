#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n ; cin >> n;
    vector<ll> a(n+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    map<ll,ll> position;
    for(ll i = 1 ; i <= n ; i++){
        position[a[i]] = i;
    }
    bool found = false;
    ll left = 0;
    ll right = 0;
    for(ll i = 1 ; i <= n ; i++){
        if(a[i] != n-i+1){
            left = i;
            right = position[n-i+1];
            found = true;
            break;
        }
    }
    if(found){
        while(left <= right){
            ll temp = a[left];
            a[left] = a[right];
            a[right] = temp;   
            left++;
            right--;
        }
    }
    for(ll i = 1 ; i <= n ; i++) cout << a[i] << " " ;
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