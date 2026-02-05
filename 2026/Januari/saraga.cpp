#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s,t ; cin >> s >> t;
    map<ll,vector<ll>> idxS,idxT;
    ll ns = s.length();
    ll nt = t.length();
    for(ll i = 0 ; i < ns ; i++){
        idxS[s[i]].push_back(i);
    }
    for(ll i = nt-1 ; i>= 0 ; i--){
        idxT[t[i]].push_back(i);
    }
    for(auto crc : idxS){
        char cur = crc.first;
        if(idxT[cur].empty()) continue;
        
        
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