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
    int n ; cin >> n;
    vector<ll> facts;
    for(ll i = 2; i  * i <= n ; i++){
        if(n % i == 0){
            facts.push_back(i);
        }
        while(n % i == 0){
            n = n/i;
        }
    }
    if(n > 1){
        facts.push_back(n);
    }
    ll ans = 1;
    for(auto x : facts) ans = ans * x;
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
