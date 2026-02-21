#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n;
    int l ; cin >> l;
    vector<vector<int>> p(n+1,vector<int> (l+1));
    vector<int> c(n+1);
    for(int i = 1; i <= n ; i++){
        cin >> c[i];
        for(int j = 1 ; j <= l ; j++){
            cin >> p[i][j];
        }
    }
    vector<vector<int>> adj(n+1);
    map<string,int> index;
    for(int i = 1; i <= n ; i++){
        vector<int> cur = p[i];
        string curs;
        for(int j = 1 ; j <= l ; j++){
            curs += to_string(cur[j]);
        }
        index[curs] = i;
    }
    for(int i =  1 ; i <= n ; i++){
        vector<int> cur = p[i];
        string cus ;
        for(int j = 1; j <= l ; j++){
            cus += to_string(cur[j]);
        }
        for(int k = 0 ; k < l-1; k++){
            string curswap = cus;
            swap(curswap[k],curswap[k+1]);
            auto it = index.find(curswap);
            if(it != index.end() && it->second > i) {
                adj[i].push_back(it->second);
            }
        }
    }
    string first;
    for(int i = 1; i <= l ; i++){
        first += to_string(i);
    }
    index[first] = 0;
    for(int i = 0 ; i < l -1; i++){
        string crs = first;
        swap(crs[i],crs[i+1]);
        auto it = index.find(crs);
        if(it != index.end() && it->second > 0) {
            adj[0].push_back(it->second);
        }
    }
    vector<int> dp(n+1);
    c[0] = 0;
    for(int i = n ; i >= 0 ; i--){
        dp[i] = c[i];
        for(auto v : adj[i]){
            dp[i] = max(dp[i], c[i] + dp[v]);
        }
    }
    cout << dp[0] << endl;

    return 0;
}