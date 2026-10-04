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
// f(p) = p^2 -px + y

bool isSquare(ll n){
    if(n < 0) return false;
    ll root = round(sqrt(n));
    return root * root == n;
}
void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    map<ll,ll> cnt;
    for(auto x : a) cnt[x]++;
    int q ; cin >> q;
    while(q--){
        ll x,y; cin >> x >> y;
        ll cek = x * x - 4 * y;
        if(!isSquare(cek)){
            cout << 0 << " ";
            continue;
        }
        ll cek2 = x + (ll) sqrt(cek);
        if(cek2 %2 != 0){
            cout << 0 << " ";
            continue;
        }

        ll val1 = cek2/2;
        ll val2 = (x - (ll)sqrt(cek))/2;
        auto it1 = cnt.find(val1);
        auto it2 = cnt.find(val2);
        if(it1 == cnt.end() || it2 == cnt.end()){
            cout << 0 << " ";
            continue;
        }
        ll cnt1 = it1->second;
        ll cnt2 = it2->second;

        ll ans;
        if(val1 == val2){
            ans = (cnt1 * (cnt1-1))/2;
        }
        else ans = cnt1 * cnt2;
        cout << ans << " ";\
    }
    cout << '\n';
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
