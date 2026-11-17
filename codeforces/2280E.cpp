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
    ll n,l; cin >> n >> l;
    vector<ll> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    sort(a.begin()+1,a.end());

    vector<ll> possibles;

    for(ll i = 1; i <= l;){
        ll q = l/i;
        if(l % i == 0) possibles.push_back(q-1);
        else possibles.push_back(q);
        i = l/q+1;
    }
    ll ans = 1e16;
    for(auto x : possibles){
        int last = x;

        // cout << x << " " << last << endl;
        ll curans = 0;
        for(int i = 1; i <= n-1 ; i++){
            ll temp = min(a[i],l/x);
            curans += abs(a[i] - temp);
        }
        curans += abs(a[n] - last);
        ans = min(ans,curans);
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
