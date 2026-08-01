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
    ll n,k ; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    sort(a.begin()+1,a.end());
    if(n == 1){
        cout << max(0LL, (ll)a[1] - k) << endl;
        return;
    }
    vector<ll> pr(n+1);
    pr[0] = 0;
    for(int i = 1; i <= n ; i++) pr[i] = pr[i-1] + a[i];

    if (pr[n] <= k) {
        cout << 0 << endl;
        return;
    }
    ll ans = 2e15;
    ll low = 0;
    ll high = 2e15;
    while(low <= high){
        ll mid = low + (high - low)/2;
        bool bisa = false;
        for(int l = 0; l <= min((ll)n-1,mid) ; l++){
            ll p = mid- l;
            if((l+1) * (a[1] - p) + pr[n-l] - pr[1] <= k){
                bisa = true;
                break;
            }
        }
        if(bisa){
            ans = min(mid,ans);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
