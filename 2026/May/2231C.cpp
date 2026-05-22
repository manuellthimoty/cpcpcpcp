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
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    unordered_map<int, int> count;
    unordered_map<int, int> ways;
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        int langkah = 0;
        count[cur] ++;
        if(cur == 1){
            count[cur+1] ++;
            ways[cur+1]++;
        }
        while(cur > 1){
            if(cur % 2 == 0){
                cur = cur/2;
            }
            else{
                cur++;
            }
            langkah++;
            ways[cur] += langkah;
            count[cur] ++ ;
        }
    }
    int ans = 1e9;
    // for(auto x : count){
    //     if(x.second == n){
    //         ans = min(ans, ways[x.first]);
    //     }
    // }
    int mn = *min_element(a.begin(),a.end());
    vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(mn);
    while(mn > 1){
        if(mn % 2 == 0){
            mn = mn/2;
        }
        else mn++;
        p.push_back(mn);
    }
    for(auto bisa : p){
        if(count[bisa] == n){
            ans = min(ans, ways[bisa]);
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
