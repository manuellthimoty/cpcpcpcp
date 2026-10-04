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

void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    // ai - 2k = 2k - aj
    // ai + aj = 4k
    map<int,int> f;
    for(auto x: a) f[x]++;
    int cntOdd = 0;
    int cntsame = 0;
    for(auto x : a){
        cntsame = max(cntsame,f[x]);
    }
    for(auto x : a){
        if(x % 2 == 1){
            cntOdd ++;
        }
    }
    int cnt4s = 0;
    for(auto x : a){
        if(x % 4 == 0){
            cnt4s ++;
        }
    }
    int cnt4mod2 = 0;
    for(auto x : a){
        if(x % 4 == 2){
            cnt4mod2++;
        }
    }
    int ans = max({cntOdd,cnt4s,cnt4mod2,cntsame});
    cout << ans << endl;

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
