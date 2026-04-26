#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; 
    cin >> n;
    
    // Gunakan vector<ll> agar saat dikalikan dengan jarak, hasilnya aman dari overflow
    vector<ll> a(n+1); 
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    
    vector<int> urutan;
    ll mn = a[1]; 
    urutan.push_back(1);
    
    for(int i = 2 ; i <= n ; i++){
        if(a[i] < mn){
            urutan.push_back(i);
            mn = a[i];
        }
    }
    
    if(urutan.back() != n){
        urutan.push_back(n);
    }
    
    ll ans = 0; 
    for(int i = 0 ; i < urutan.size() - 1 ; i++){
        ans += a[urutan[i]] * (urutan[i+1] - urutan[i]);
    }
    
    cout << ans << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}