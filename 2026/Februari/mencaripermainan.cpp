#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n ; cin >> n;
    int k ; cin >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    map<int,int> freq;
    for(int i = 0 ; i < n ; i++){
        freq[a[i]] ++;
    }
    vector<int> f;
    for(auto x : freq){
        f.push_back(x.second / 2);
    }
    sort(f.begin(),f.end());
    reverse(f.begin(),f.end());
    int target = min((int)f.size(),k);
    int ans = 0;
    for(int i = 0 ; i < target ; i++){
        ans += f[i];
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
};
