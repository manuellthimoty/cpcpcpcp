#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll p,q ; cin >> p >> q;
    if(3 * p >= 2 * q && q > p){
        cout << "Bob" << endl;
    }
    else{
        cout << "Alice" << endl;
    }
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
