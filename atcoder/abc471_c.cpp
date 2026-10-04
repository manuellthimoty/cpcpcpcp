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


int main() {
    GK();

    int n ; cin >> n;
    set<int> a;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        a.insert(x);
    }
    int cur = 0;
    ll ans = 0;
    while (!a.empty()) {
        auto up = a.lower_bound(cur);

        if (up == a.end()) {
            auto down = prev(a.end());

            ans += abs((ll)cur - *down);
            cur = *down;

            a.erase(down);
        }
        else if (up == a.begin()) {
            ans += abs((ll)cur - *up);
            cur = *up;

            a.erase(up);
        }
        else {
            auto down = prev(up);

            ll distUp = abs((ll)cur - *up);
            ll distDown = abs((ll)cur - *down);

            if (distDown <= distUp) {
                ans += distDown;
                cur = *down;

                a.erase(down);
            }
            else {
                ans += distUp;
                cur = *up;

                a.erase(up);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
