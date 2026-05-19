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
ll MAXVAL = 1e17;
vector<ll> results;
void generate(ll current, ll d1, ll d2){
    results.push_back(current);
    if (current <= (MAXVAL - d1) / 10) {
        ll next_val = current * 10 + d1;
        if (next_val > current) {
            generate(next_val, d1, d2);
        }
    }
    if (d1 != d2 && current <= (MAXVAL - d2) / 10) {
        ll next_val = current * 10 + d2;
        if (next_val > current) {
            generate(next_val, d1, d2);
        }
    }
}

void precompute(){
    
}

void solve(){
    results.clear();
    ll a,n ; cin >> a >> n;
    ll d1,d2 ; cin >> d1 >> d2;
    if(d1 == 0 || d2 == 0) results.push_back(0);
    if (d1 > 0 && d1 <= MAXVAL) generate(d1, d1, d2);
    if (d2 > 0 && d2 != d1 && d2 <= MAXVAL) generate(d2, d1, d2);
    ll ans = 1e17;
    for(auto b : results){
        ans = min(ans, abs(a-b));
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
