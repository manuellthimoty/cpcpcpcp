#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q; cin >> q;
    while(q--){
        ll n,k; cin >> n >> k;
        // if(n % 2 == 0){
        //     if(k <= n/2){
        //         cout << 2*k << endl;
        //     }
        //     else{
        //         cout << 2*(k - n/2) -1 << endl;
        //     }
        // }
        // else{
        //     if(k <= n/2){
        //         cout << 2 * k << endl;
        //     }
        //     else{

        //     }
        // }
        if(k<= n/2) cout << 2*k << endl;
        else cout << 2*(k - n/2) - 1 << endl;
    }
    

    return 0;
}