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
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)

// 4 1 3 2 2 4 1 3
// 4 3 2 

void solve(){
    int n; cin >> n;
    vector<ll> f(101,0);
    ll mx = 0;
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        f[a]++;
        mx = max(mx,(ll)a);
    }    
    vector<ll> ans;
    while(mx > 0){
        f[mx]--;
        int i = mx;
        ans.push_back(i);
        i--;
        while(i > 0){
            if(f[i] > 0){
                f[i]--;
                ans.push_back(i);
            }
            i--;
        }
        while(f[mx] == 0){
            mx--;
        }
    }
    for(int i = 0; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
