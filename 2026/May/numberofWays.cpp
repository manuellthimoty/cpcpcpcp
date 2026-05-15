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
    vector<int> a(n);
    input(a,0,n);
    vector<ll> pref(n);
    pref[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        pref[i] = pref[i-1] + a[i];
    }

    if(pref[n-1] % 3 != 0){
        cout << 0 << endl;
        
        return;
    }

    ll pi = pref[n-1]/3;

    ll pj = 2 * pi;

    vector<ll> cont;
    
    for(int i = 0 ; i < n-1 ; i++){
        if(pref[i] == pi || pref[i] == pj){
            cont.push_back(pref[i]);
        }
    }
    ll sz = cont.size();
    vector<ll> suffj(sz,0);
    // cout << "!";
    if(sz == 0){
        cout << 0 << endl;
        return;
    }
    // for(auto c : cont){
    //     cout << c << " ";
    // }
    if(pref[n-1] == 0){
        cout << (sz * (sz-1))/2 << endl;
        return;
    }
    if(cont[sz-1] == pj) suffj[sz-1] = 1;
    for(ll i = sz -2 ; i >=0 ; i--){
        if(cont[i] == pj){
            suffj[i] = suffj[i+1] + 1;
        }
        else {
            suffj[i] = suffj[i+1];
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < sz-1 ; i++){
        if(cont[i] == pi){
            ans += suffj[i+1];
        }
    }
    cout << ans << endl;
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
