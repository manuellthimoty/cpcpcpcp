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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    int first_1 = n, last_1 = -1;
    int first_minus = -1, last_minus = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            if (first_1 == n) first_1 = i;
            last_1 = i;
        } else if (a[i] == -1) {
            if (first_minus == -1) first_minus = i;
            last_minus = i;
        }
    }

    if (first_minus != -1 && first_minus < first_1) {
        a[first_minus] = 1;
    }
    if (last_minus != -1 && last_minus > last_1 && last_minus != first_minus) {
        a[last_minus] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
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
