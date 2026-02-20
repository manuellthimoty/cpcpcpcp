#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n ; cin >> n;
    bool ans = false;
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        if(a == 67){
            ans = true;
        }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
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
