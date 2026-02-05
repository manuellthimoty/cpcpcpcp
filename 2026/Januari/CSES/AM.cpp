#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n ; cin >> n;
    vector<vector<char>> ans(n,vector<char> (n,'.'));
    ll mid = n/2;
    for(ll i = 0 ; i <= mid ; i++){
        ans[i][i] = '#';
    }
    for(ll i = mid +1 ; i < n ; i++){
        ans[n-i-1][i] = '#';
    }
    for(ll i = 0 ; i < n ; i++){
        ans[i][0] = '#';
        ans[i][n-1] = '#';
    }
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < n ; j++){
            cout << ans[i][j] ;
        }
        cout << endl;
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