#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; 
    cin >> n;
    vector<int> b(n);
    for(int i = 0 ; i < n ; i++){
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    auto it = unique(b.begin(),b.end());
    b.erase(it,b.end());
    int size = b.size();
    // int maximum = -1;
    // for(int i = 0 ; i < size ; i++){
    //     int count = 1;
    //     for(int j = 0 ; j < size ; j++){
    //         if(j==i) continue;
    //         if(b[j]>b[i]) count++;
    //     }
    //     maximum = max(count,maximum); 
    // }                                                                                                                                                    
    // cout << maximum << endl;
    cout << size << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
