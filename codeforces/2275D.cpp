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
    ll k; cin >> k;
    vector<ll> a(n),b(n),c(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    ll fixed = 4e18;
    vector<ll> sorted;
    vector<ll> s(n),v(n);
    for(int i = 0 ; i < n ; i++){
        if(a[i] == b[i] && b[i] == c[i]){
            fixed = min(fixed,3 * a[i]);
            s[i] = 3 * a[i];
            v[i] = 3 * a[i];
        }
        
        else{
            ll sum = a[i] + b[i] + c[i];
            s[i] = sum;
            if(a[i] <= b[i] && b[i] <= c[i]){
                ll d = min(b[i]-a[i]+1,c[i]-b[i]+1);
                v[i] = sum - 2 * d;
            }
            else v[i] = sum;
        }
    }

    ll low = -4e18, high = fixed;
    ll ans = low;

    while(low <= high){
        ll mid = low + (high - low) / 2;
        ll cost = 0;
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(mid > s[i]){
                ll req = mid - v[i];
                // cost += mid - v[i];
                // cost + req > k
                if(k - cost < req){
                    ok = false;
                    break;
                }
                cost += req;
                // if(cost > k){
                //     ok= false;
                //     break;
                // }
            }
        }
        
        if(ok){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
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
