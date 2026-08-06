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
// a[1] = b[1]
// a[2] = b[1] + b[2]
// a[n] = b[1] + b[2] + .. + b[n]
// we need to minimize pr[1],pr[2], ...,p[n], but also p[i] >=1 for every i
void solve(){
    int n ; cin >> n;
    multiset<ll> b;
    for(int i = 0 ; i < n ; i++){
        ll val; cin >> val; b.insert(val);
    }
    vector<ll> a;
    ll current_sum = 0;
    for (int i = 0; i < n; i++) {
        auto it = b.lower_bound(1 - current_sum);
        if (it == b.end()) {
            cout << -1 << "\n";
            return;
        }
        ll chosen_val = *it;
        current_sum += chosen_val;
        a.push_back(current_sum);
        b.erase(it);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
