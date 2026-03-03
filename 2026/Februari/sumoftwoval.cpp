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
    int n; cin >> n;
    int x ; cin >> x;
    vint a(n);
    input(a,0,n);
    map<int,vector<int>> idx;
    for(int i = 0 ; i <n ; i++){
        idx[a[i]].push_back(i);
    }
    set<int> cur;
    for(int i = 0 ;i <n ; i++){
        int target = x - a[i];
        if(cur.find(target) != cur.end()){
            cout << idx[target][0] + 1<< " " << i + 1 << endl;
            return;
        }
        cur.insert(a[i]);
    }
    cout << "IMPOSSIBLE";
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
