#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

void solve(){
    int n ; cin >> n;
    vint b(n); input(b,0,n);
    map<int,int> freq;
    for(int i = 0 ; i < n ; i++){
        freq[b[i]]++;
    }
    for(auto f : freq){
        if(f.second % f.first != 0){
            cout << -1 << endl;
            return;
        }
    }
    map<int,vector<int>> res;
    for(int i = 0 ; i < n ; i++){
        res[b[i]].push_back(i);
    }
    int cur = 1;
    vint ans(n);

    for(auto r : res){
        int cnt = 0;
        for(auto x : r.second){        
            if(cnt == r.first){
                cnt = 0;
                cur++;
            }
            ans[x] = cur;
            cnt++;
        }
        cur++;
    }
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
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
