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
    ll n,c; cin >> n >> c;
    ll ans = 0;
    vector<ll> s(n);
    for(int i = 0 ; i < n ; i++) cin >> s[i];
    ans += (c *(c+1))/2 + (c+1);

    ll cnt1 = 0;
    for(auto x : s){
        cnt1 += (x/2) + 1;
    }
    ll cnt2 = 0;
    for(auto x : s){
        cnt2 += (c-x)+1;
    }
    ans -= cnt1;
    ans -= cnt2;
    ll cnto = 0;
    ll cnte = 0;
    for(auto x : s){
        if(x %2 == 1) cnto++;
        else cnte ++;
    }
    ans += (cnto * (cnto-1))/2;
    ans += (cnte * (cnte-1))/2;
    ans += n;
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
