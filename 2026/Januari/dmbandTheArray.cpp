#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n,s,x ; cin >> n >> s >> x;
    ll sum = 0 ;
    for (ll i = 0 ; i < n ; i++){
        ll nums ; cin >> nums;
        sum+= nums;
    }
    if(s < sum){
        cout << "NO" << endl;
        return;
    }
    ll selisih = s - sum;
    if(selisih % x != 0){
       cout << "NO" << endl;
       return;
    }
    cout << "YES" << endl;
    
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