#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k ; cin >> n >> k ;
    string s;
    s.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    int ans = 0;
    int cur = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
            cur = k;
            continue;
        }
        if(cur>0){
            cur--;
            continue;
        }
        else{
            if(cur == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
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
