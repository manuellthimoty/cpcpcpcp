#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s ; cin >> s;
    ll n = s.length();
    vector<ll> prog(n);
    prog[0] = 1;
    for(ll i = 1 ; i < n ; i++){
        if(s[i] == '('){
            prog[i] = 1 + prog[i-1];
        }
        else{
            prog[i] = prog[i-1] -1;
        }
    }
    for(ll i = 0 ; i < n-1 ; i++){
        
        if(prog[i] == 0 && prog[i+1] == 1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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