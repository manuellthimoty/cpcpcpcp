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

    string s;
    cin >> s;
    bool hasPlus = false;
    bool hasMinus = false;

    for (int i = 0; i < n; ) {

        if (s[i] == '0') {
            i++;
            continue;
        }
        vector<int> len;
        int j = i;
        while (j < n && s[j] != '0') {
            int k = j;
            while (k < n && s[k] == s[j]) k++;
            len.push_back(k - j);
            if (s[j] == '+') hasPlus = true;
            else hasMinus = true;
            j = k;
        }

        if (len.size() >= 3) {
            for (int k = 1; k + 1 < (int)len.size(); k++) {
                if (len[k] % 2 == 0) {
                    cout << 3 << '\n';
                    return;
                }
            }
        }

        i = j;
    }

    if (!hasPlus || !hasMinus) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
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
