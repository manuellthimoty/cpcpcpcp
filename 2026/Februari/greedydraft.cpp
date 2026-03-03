#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m ; cin >> n >> m;
    vector<vector<int>> li(n);
    for(int i = 0 ; i < n ; i++){
        int l ; cin >> l;
        for(int j = 0 ; j < l ; j++){
            int x ; cin >> x;
            li[i].push_back(x);
        }
    }
    // cout <<"done";
    set<int> ans;
    vector<int> final(n);
    for(int i = 0 ; i < n ; i++){
        bool found = false;
        for(auto x : li[i]){
            if(ans.find(x) == ans.end()){
                ans.insert(x);
                final[i] = x;
                found = true;
                break;
            }
        }
        if(!found){
            final[i] = 0;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << final[i] << endl;
    }
    

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
}
