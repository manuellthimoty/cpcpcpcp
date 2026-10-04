#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
void solve(){
    ll x,y,z;
    cin >> x >> y >> z;
    ll res = ((x & y) & ~z) | ((x & z) & ~y) | ((y & z) & ~x);
    if(res == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        solve();
    }

}
