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

ll hitung(ll a, ll b, ll mid){
    ll len= b - a + 1;
    if (b <= mid) {
        ll L_dist = mid - a;
        ll R_dist = mid - b;
        return len * (L_dist + R_dist) / 2;
    } 
    else if (a >= mid) {
        ll L_dist = a - mid;
        ll R_dist = b - mid;
        return len * (L_dist + R_dist) / 2;
    } 
    else {
        ll L_dist = mid - a;
        ll R_dist = b - mid;
        ll cost_kiri = L_dist *(L_dist + 1) / 2;
        ll cost_kanan = R_dist *(R_dist + 1) / 2;
        return cost_kiri + cost_kanan;
    }
}

void solve(){
    ll n, m, k; 
    cin >> n >> m >> k;
    
    vector<pair<ll,ll>> sisa;
    vector<ll> p(m);
    for(int i = 0 ; i < m ; i++) cin >> p[i];
    p.push_back(0);
    p.push_back(n + 1);
    sort(p.begin(), p.end());
    for(size_t i = 1 ; i < p.size() ; i++){
        ll selisih = p[i] - p[i-1] - 1;
        if(selisih > 0){
            sisa.push_back({p[i-1] + 1, selisih});
        }
    }
    
    ll mid = (n + 1) / 2;
    ll ans = -1;
    for(auto s : sisa){
        if(s.second < k) continue;
        ll L = s.first;
        ll R = L + s.second -1 ;
        ll a,b;
        if( R <= mid){
            b = R;
            a = R-k+1;
        }
        else if(L >= mid){
            a = L;
            b = L + k-1;
        }
        else{
            ll optimal = mid-k/2;
            a = max(L, min(R - k + 1, optimal));
            b = a + k - 1;
        }
        ll cur = hitung(a,b,mid);
        if(ans == -1){
            ans = cur;
        }
        else ans = min(ans,cur);
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
