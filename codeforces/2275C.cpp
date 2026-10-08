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
    vector<ll> a(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<ll> t(n+1);
    for(int i = 1; i <= n-4 ; i++) t[i] = a[i] + a[i+2] - a[i+4];
    map<ll,ll> cnt;
    for(int i =1 ; i <= n-4 ; i++){
        cnt[t[i]]++;
    }
    ll ans = 0;
    for(auto x : cnt){
        ll curr = x.second;
        ans += (curr * (curr-1))/2;
    }

    for(int i = 1; i <= n -4 ; i++){
        ll c = 0;
        if(i+2 <= n-4 && t[i] == t[i+2]) c++;
        if(i+4 <= n-4 && t[i] == t[i+4]) c++;
        ans -= c;
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
