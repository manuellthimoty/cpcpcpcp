#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n ; cin >> n;
    string s;
    s.resize(n);
    cin >> s;
    int count1 = 0;
    for(int i = 0; i < n ; i++){
        if(s[i] == '1') count1 ++;
    }
    string sorted;
    for(int i = 0 ; i < n - count1 ; i++){
        sorted += '0';
    }
    for(int i = 0 ; i < count1 ; i++){
        sorted += '1';
    }
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        if(s[i] == '1' && sorted[i] == '0'){
            ans ++;
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
