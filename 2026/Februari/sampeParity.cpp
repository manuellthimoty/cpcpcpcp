#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k ; cin >> n >> k;

    if(n % 2 == 1){
        // n ganjil, maka haruslah ai semuanya ganjil
        // syaratnya adalah k ganil
        // min dari ai = 1
        
        if(n < k){
            cout << "NO" << endl;
            return;
        }
        if(k % 2 == 0){
            cout << "NO" << endl;
            return;
        }
        // bagi n ke k
        ll each = n/k;
        if(each % 2 == 0) each --;
        ll sisa = n - each * k;
        cout << "YES" << endl;
        for(ll i = 0 ; i < k ; i++){
            if(i == 0) cout << each + sisa << " ";
            else cout << each << " ";
        }
        cout << endl;
    }
    if(n % 2 == 0){
        if(n < k){
            cout << "NO" << endl;
            return;
        }
        // kalo k genap, maka ai bisa keduanya ganjil ataupun genap
        if( k % 2 == 0){
            // case 1 : semuanya ganjil
            ll each = n / k;
            ll sisa = n - each * k;
            cout << "YES" << endl;
            for(ll i = 0 ; i < k ; i++){
                if(i == 0) cout << each + sisa << " ";
                else cout << each << " ";
            }
            cout << endl;
        }
        else{
            if(n < 2 * k){
                cout << "NO" << endl;
                return;
            }
            ll each = (n / (2*k)) * 2;
            ll sisa = n - k * each;
            cout << "YES" << endl;
            for(ll i = 0 ; i < k ; i++){
                if(i == 0) cout << each + sisa << " ";
                else cout << each << " ";
            }
            cout << endl;
        }
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
