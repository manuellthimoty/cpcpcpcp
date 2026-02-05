#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("gymnastics.in", "r", stdin);

    int k,n ; cin >> k >> n;
    vector<vector<int>> pos(k+1,vector<int> (n+1));
    vector<int> a(n+1,0);
    for(int i = 1 ; i <= k ; i++){
        for(int j = 1; j<= n ; j++){
            int nums ; cin >> nums;
            if(i == 1){
                a[j] = nums;
            }
            pos[i][nums] = j;
            // cout << pos[i][nums] << " ";
        }
        // cout << endl;
    }
    vector<pair<int,int>> cand;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            cand.push_back(make_pair(a[i],a[j]));
        }
    }
    int ans = 0;
    for(auto x : cand){
        bool oks = true;
        for(int i = 2 ; i <= k ; i++){
            if(pos[i][x.first] > pos[i][x.second]){
                oks = false;
                break;
            }
        }
        if(oks){
            ans++;
        }
    }
    freopen("gymnastics.out", "w", stdout);
    
    cout << ans << endl;
    

    return 0;
}