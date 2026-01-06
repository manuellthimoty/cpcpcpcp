#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n ; cin >> n ;
    int y,r; cin >> y >> r;
    int yellow = y/2;
    cout << min(n,r+yellow) << endl;;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t;
    while(t--){
        solve();
    }
}