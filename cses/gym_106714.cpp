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
    int n; cin >> n;
    int c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 2) c2++;
        else c3++;
    }

    if (c2 > 0 && c3 > 0) {
        cout << "Yes\n";
    } else if (c3 == 0) {
        cout << (n % 2 != 0 ? "Yes" : "No") << "\n";
    } else {
        cout << (n % 3 != 0 ? "Yes" : "No") << "\n";
    }
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
