#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll a,b ; cin >> a >> b;
        ll sum = a + b;
        if((a+b)% 3 != 0){
            cout << "NO" <<endl;
            continue;
        }
        if(min(a,b) < sum/3){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    

    return 0;
}