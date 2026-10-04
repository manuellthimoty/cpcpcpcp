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
    int n,k,p,q ; cin >> n >> k >> p >> q;
    vint a(n+1);
    input(a,1,n+1);
    vll pq(n+1);
    vll qp(n+1);
    vll mins(n+1);
    vll prefpq(n+1);
    vll prefqp(n+1);
    for(ll i = 1 ; i <= n ; i++){
        pq[i] = (a[i] % p) % q;
        qp[i] = (a[i] % q) % p;
        mins[i] = min(pq[i],qp[i]);
    }
    prefpq[1] = pq[1]; prefqp[1] = qp[1];

    for(ll i = 2 ; i <= n ; i++){
        prefpq[i] = prefpq[i-1] + pq[i];
        prefqp[i] = prefqp[i-1] + qp[i];
    }

    vll prefMin(n+1);
    prefMin[1] = mins[1];
    for(ll i = 2 ; i <= n ; i++) prefMin[i] = prefMin[i-1] + mins[i];
    // start dri index 0
    ll ans = min(prefpq[k], prefqp[k]) + prefMin[n] - prefMin[k];
    
    // kanan, berarti dari n - m + 1 = k -> m = n - k +1
    ll palingkanan = prefMin[n-k] + min(prefpq[n] - prefpq[n-k],prefqp[n] - prefqp[n-k]);
    for(ll i = 2 ; i <= n-k+1 ; i++){
        // left = i , right = i+k-1
        ll jumlahtengah = min(prefpq[i+k-1] - prefpq[i-1], prefqp[i+k-1] - prefqp[i-1]);
        ll jumlahkiri = prefMin[i-1];
        ll jumlahkanan = prefMin[n] - prefMin[i+k-1];
        ans = min(ans, jumlahkiri + jumlahtengah + jumlahkanan);
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
