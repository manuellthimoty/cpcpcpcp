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
const int mxA = 1e6;
int spf[mxA + 1];
// vector<vector<int>> primefact(mxA+1);

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
void solve(){
    int n ; cin >> n;
    ll total_prime = 0;
    ll total_power = 0;
    while(n > 1){
        int curP = spf[n];
        total_prime ++;
        ll cnt = 0;
        while(n % curP == 0){
            cnt++;
            n /= curP;
        }
        total_power += cnt;
    }
    cout << total_prime + total_power - 1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
