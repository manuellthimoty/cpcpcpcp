#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n ; cin >> n;
    string s; s.resize(n); cin >> s;
    int ans = 0;
    int curzero = 0;
    int left = 0;
    int right = 0;
    bool doneleft = false;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '0'){
            curzero ++;
        }
        else{
            if(s[0] == '0' && !doneleft){
                left = curzero;
                doneleft = true;
            }
            ans = max(ans,curzero);
            curzero = 0;
        }
    }
    if(s[n-1] == '0'){
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '0'){
                right ++;
            }
            else{
                break;
            }
        }
    }
    ans = max(ans, left + right);
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
