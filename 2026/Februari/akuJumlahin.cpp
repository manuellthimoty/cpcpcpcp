#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll N; cin >> N;
    ll left = 0;
    ll right = 0;
    ll p = 0;
    for(ll i = 2 ; i *i <= 2 * N ; i++){
        if((2*N) % i == 0){
            ll c = (2*N/i);
            ll s = c - i + 1;
            if(s >= 2 && (s%2) == 0){
                p = i;
                left = s/2;
                right = left + i -1;
                break;
            }
        }
    }
    if(p == 0){
        cout << "GAK BISA" << endl;
    }
    else if(p == 2){
        cout << N << " = " << left << " + " << right << endl;
    }
    else{
        cout << N << " = " << left << " + ... + " << right << endl;
    }
    // cout << left << " " << right;
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