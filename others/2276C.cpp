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
    int k; cin >> k;

    vector<int> a(n+1);
    for(int i =1 ; i <= n ; i++) cin >> a[i];
    vector<ll> p(n+1,0);
    for(int i = 1; i <= n ; i++) p[i] = p[i-1] + a[i];
    for(int i = 1; i <= n ; i++) p[i] %= k;

    vector<vector<ll>> all(k+1);
    for(int i = 0; i <= n ; i++){
        all[p[i]].push_back(i);
    }
    ll ans = 0;
    for(ll i = 0 ; i < k ; i++){
        int curlen = all[i].size();
        vector<ll>& curm = all[i];
        for(int j = 0 ; j < curlen ; j++){
            int low = 0;
            int high = curlen-1;
            int idx = curlen;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(curm[mid] > (curm[j]+k)){
                    idx = min(idx,mid);
                    high = mid-1;
                }
                else low = mid+1;
            }
            if(idx == curlen) continue;
            else ans += curlen - idx;
        }
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
