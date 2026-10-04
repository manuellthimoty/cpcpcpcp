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
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    int L = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            L++;
        }
    }

    bool can_minus_2 = false;
    bool can_minus_1 = false;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != s[i-1] && s[i] != s[i+1]) {
            if (s[i-1] == s[i+1]) {
                can_minus_2 = true; 
            } else {
                can_minus_1 = true;
            }
        }
    }
    if (can_minus_2) {
        cout << L - 2 << "\n";
    } else if (can_minus_1) {
        cout << L - 1 << "\n";
    } else {
        cout << L << "\n";
    }
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
