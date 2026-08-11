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
    int n,m ; cin >> n >> m;
    vector<pair<int,int>> p(n+1);
    for(int i =1 ; i <= n ; i++) {
        cin >> p[i].first; 
        p[i].first %= m;
    }
    for(int i =1 ; i <= n ; i++) cin >> p[i].second;

    sort(p.begin()+1,p.end());
    vector<int> all;
    for(int i = 1 ; i <= n ; i++){
        if(all.empty() || all.back() != p[i].first){
            all.push_back(p[i].first);
        }
    }

    vector<ll> pref(n+1,0);
    for(int i = 1; i <= n ; i++) pref[i] = pref[i-1] + p[i].second;
    vector<ll> suff(n+2,0);
    for(int i = n ; i >= 1; i--) suff[i] = suff[i+1] + p[i].second;
    ll ans = 0;

    vector<int> cand;
    for(int x : all){
        if(m -x >=1) cand.push_back(m-x-1);
    }
    cand.push_back(m-1);

    for(auto k : cand){
        int check = m - k;
        int low = 1; int high = n;
        int idx = n+1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(p[mid].first >= check){
                idx = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        ll curr = 1LL * k * pref[n] - 1LL * m * suff[idx];
        ans = max(ans,curr);
    }
    ll f0 = 0;
    for(int i = 1; i <= n ; i++){
        f0 += 1LL * (p[i].first % m) * p[i].second;
    }
    cout << f0 + ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
