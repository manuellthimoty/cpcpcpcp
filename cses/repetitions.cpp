#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // unordered_map<char,ll> freq;
    string s; cin >> s;
    ll ans = -1;
    ll count = 1;
    if(s.size() == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1 ; i < s.size() ; i++){
        if(s[i] == s[i-1]){
            count++;
        }
        else{
            ans = max(count,ans);
            count = 1;
        }
        ans = max(ans,count);
    }
    cout << ans << endl;
    

    return 0;
}