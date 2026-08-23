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
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    set<pair<ll, ll>> st;
    
    auto get_next_white = [&](ll x) -> ll {
        auto it = st.upper_bound({x, 2e18});
        if (it != st.begin()) {
            auto prev = it; --prev;
            if (prev->first <= x && x <= prev->second) {
                return prev->second + 1;
            }
        }
        return x;
    };

    auto add_black = [&](ll x) {
        ll L = x, R = x;
        auto it = st.upper_bound({x + 1, 2e18});
        vector<decltype(it)> to_erase;
        
        auto curr_it = it;
        while (curr_it != st.begin()) {
            --curr_it;
            if (curr_it->second >= x - 1) {
                L = min(L, curr_it->first);
                R = max(R, curr_it->second);
                to_erase.push_back(curr_it);
            } else {
                break; 
            }
        }
        
        for (auto erase_it : to_erase) {
            st.erase(erase_it);
        }
        st.insert({L, R});
    };

    for (int i = 0; i < m; ++i) {
        ll a;
        cin >> a;
        add_black(a);
    }

    ll curr = 1;
    for (char c : s) {
        if (c == 'A') {
            curr = curr + 1;
            add_black(curr);
        } else { // c == 'B'
            ll y = get_next_white(curr + 1);
            add_black(y);
            curr = get_next_white(curr + 1); 
        }
    }

    ll total_black = 0;
    for (auto p : st) {
        total_black += (p.second - p.first + 1);
    }
    cout << total_black << "\n";

    for (auto p : st) {
        for (ll i = p.first; i <= p.second; ++i) {
            cout << i << " ";
        }
    }
    cout << "\n";
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
