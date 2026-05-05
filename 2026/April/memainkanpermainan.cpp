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
    ll n,t; cin >> n >> t;
    vector<pair<ll,ll>> p(n); 
    for(int i = 0 ; i < n ; i++){
        ll a,b; cin >> a >> b;
        p[i] = make_pair(a,b);
    }

    ll minidxStart = -1;
    ll minValstart = 2e18; 
    
    for(int i = 0 ; i < n ; i++){
        if(p[i].first < minValstart){
            minValstart = p[i].first;
            minidxStart = i;
        }
    }
    ll minidxStart2 = -1;
    ll minValstart2 = 2e18;
    for(int i = 0 ; i < n ; i++){
        if(i == minidxStart) continue;
        if(p[i].first < minValstart2){
            minValstart2 = p[i].first;
            minidxStart2 = i;
        }
    }

    vector<ll> repeatval(n);
    for(int i = 0 ; i < n ; i++){
        repeatval[i] = p[i].first + p[i].second;
    }
    
    ll minValRep = 2e18;
    ll minidxRep = -1;
    for(int i = 0 ; i < n ; i++){
        if(i == minidxStart) continue;
        if(repeatval[i] < minValRep){
            minValRep = repeatval[i];
            minidxRep = i;
        }
    }

    ll ans1 = 0, ans2 = 0, ans3 = 0;
    if (t >= p[minidxStart].first) {
        ans1 = 1 + ((t - p[minidxStart].first) / repeatval[minidxStart]);
    }
    
    if (n > 1 && t >= p[minidxStart].first) {
        ans2 = 1 + ((t - p[minidxStart].first) / repeatval[minidxRep]);
    }
    if (n > 1) {
        ll sum_A = p[minidxStart].first + p[minidxStart2].first;
        ans3 = (t / sum_A) * 2; 
        ll sisa = t % sum_A;
        if(sisa >= p[minidxStart].first) ans3++;
    }
    
    ll ans = max({ans1, ans2, ans3});
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