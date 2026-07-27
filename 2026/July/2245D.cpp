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
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int o,i,j ; cin >> o >> i >> j;
        if(o == 1){ // ai + aj >=0 - > ai >= -aj


        }
        else{// ai + aj <=0 -> ai <= -aj

        }
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
