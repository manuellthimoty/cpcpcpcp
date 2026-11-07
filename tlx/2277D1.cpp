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
ll MOD = 998244353;

ll compute(ll n){
    ll ans = 0;
    ll cpyn = n;
    while(cpyn > 0){
        if(cpyn == 1){
            ans++;
            break;
        }
        ll p =1 ;
        ll k = 0;
        while(p-1 <= cpyn){
            p *= 2;
            k ++;
        }
        ans +=k;
        cpyn -= (p/2) -1; 
        cpyn--;
        ans %= MOD;
    }
    return ans;
    // ll case1 = p -1;
    // ll case2 = p/2 - 1;
    // ll m1 = case1 - n;
    // ll ans1 = m1 + k;
    // if(case2 == n){
    //     ans1 =  min(ans1,k);
    // }
    // ll m2 = case2 - n;
    // if(m2 >= 0){
    //     ans1 = min(ans1,m2 + k-1);
    // }
    // return ans1;

}

void solve(){
    ll l,r ; cin >> l >> r;
    ll ans = 0;
    for(ll i = l ; i <= r ; i++){
        ll cur = compute(i) % MOD;
        ans += cur;
        ans %= MOD;
    }
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
