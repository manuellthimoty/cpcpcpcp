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

vector<vector<ll>> v;
ll n;

void gen(ll idx, vector<ll>& arr, ll count, ll prod){
    if(prod > n){
        // jika sudah > n, maka hasil floornya pasti 0
        // mau + atau - dia ga ngaruh, otomatis lgsung return
        return;
    }
    if(idx == arr.size()){
        if(count >0){
            v[count].push_back(prod);
        }
        return;
    }
    if(n/prod >= arr[idx]){
        gen(idx+1,arr,count+1,prod * arr[idx]);
    }
    
    gen(idx+1,arr,count,prod);
}

void solve(){
    cin >> n;
    ll k ; cin >> k;
    vector<ll> p(k);
    v.resize(k+1);
    for(int i = 0 ; i < k ; i++) cin >> p[i];
    gen(0,p,0,1);
    ll ans = 0;
    for(int i = 1 ; i <= k ; i++){
        ll count = 0;
        for(auto a : v[i]){
            count += n/a;
        }
        if(i % 2 == 1){
            ans += count;
        }
        else ans -= count;
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
