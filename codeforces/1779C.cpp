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


// pref[1], pref[2],...,pref[m-1] > pref[m]
// pref[m] - pref[m-1] = a[m] <= 0
// pref[m] - pref[m-2] = a[m] + a[m-1] <= 0
// pref[m] - pref[m-k] = a[m] + a[m-1] + .. + a[m-k+1] <= 0
// pref[m+1] > pref[m] -> a[m+1] > 0
// 
void solve(){
    
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
