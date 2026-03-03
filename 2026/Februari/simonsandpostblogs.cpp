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
    vector<vector<int>> blogs(n);
    for(int i = 0 ; i < n; i++){
        int li ; cin >> li;
        vector<int> cur(li);
        for(int j = 0 ; j < li ; j++){
            cin >> cur[j];
        }
        set<int> seen;
        reverse(cur.begin(),cur.end());
        for(auto x : cur){
            if(seen.find(x) == seen.end()){
                blogs[i].push_back(x);
                seen.insert(x);
            }
        }
        // blogs[i] = cur;
        
    }
    vector<vector<int>> copyblogs = blogs;
    // sort(copyblogs.begin(), copyblogs.end(), [](const vector<int>& a, const vector<int>& b) {
    //     int len = min(a.size(), b.size());
    //     for (int i = 0; i < len; i++) {
    //         if (a[i] != b[i]) return a[i] < b[i];
    //     }
    //     return a.size() > b.size();
    // });
    sort(copyblogs.begin(),copyblogs.end());
    map<int,int> freq;
    vector<int> ans;
    for(int i = 0 ; i <n ; i++){
        for(auto x : copyblogs[i] ){
            if(freq[x] == 0){
                ans.push_back(x);
            }
            freq[x] = 1;
        }
    }
    for(auto a : ans) cout << a << " " ;
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
