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
    ll n ; cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<ll> prefSum(n+1);
    vector<ll> prefH(n+1);
    prefSum[1] = a[1];
    for(int i = 2 ; i <= n ; i++){
        prefSum[i] = prefSum[i-1] + a[i];
    }
    for(int i = 1 ; i <= n ; i++){
        prefH[i] = prefSum[i]/i;
    }
    vector<ll> prefMinH(n+1);
    prefMinH[1] = prefH[1];
    for(int i = 2; i <= n ; i++){
        prefMinH[i] = min(prefMinH[i-1],prefH[i]);
    }
    for(int i = 1; i <= n ; i++){
        cout << prefMinH[i] << " ";
    }
    cout << endl;
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
