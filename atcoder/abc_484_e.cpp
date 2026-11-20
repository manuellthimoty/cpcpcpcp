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


class MergeSortTree {
    ll size;
    vector<vector<ll>> tree;

    ll countInNode(ll node, ll c, ll d) const {
        const auto& v = tree[node];
        return upper_bound(v.begin(), v.end(), d)
             - lower_bound(v.begin(), v.end(), c);
    }

public:
    explicit MergeSortTree(const vector<ll>& a) {
        size = 1;
        while (size < (ll)a.size()) size <<= 1;

        tree.resize(2 * size);

        for (ll i = 0; i < (ll)a.size(); ++i) {
            tree[size + i].push_back(a[i]);
        }

        for (ll node = size - 1; node >= 1; --node) {
            const auto& left = tree[node * 2];
            const auto& right = tree[node * 2 + 1];

            tree[node].resize(left.size() + right.size());

            merge(left.begin(), left.end(),
                  right.begin(), right.end(),
                  tree[node].begin());
        }
    }

    ll query(ll l, ll r, ll c, ll d) const {
        ll answer = 0;

        l += size;
        r += size;

        while (l < r) {
            if (l & 1) {
                answer += countInNode(l, c, d);
                ++l;
            }

            if (r & 1) {
                --r;
                answer += countInNode(r, c, d);
            }

            l >>= 1;
            r >>= 1;
        }
        return answer;
    }
};


int main() {
    GK();

    ll n,l,r; cin >> n >> l >> r;
    vector<ll> A(n);
    for(int i =0 ; i < n ; i++) cin >> A[i];
    vector<ll> pref(n);
    pref[0] = A[0];
    for(int i = 1 ; i < n ; i++) pref[i] = pref[i-1] + A[i];
    MergeSortTree mgt(pref);
    // L <= pref[r] - pref[l-1] <= R
    // L - pref[r] <= -pref[l-1] <= R - pref[r]
    // pref[r] - R <= pref[l-1] <= pref[r] - L
    ll ans = 0;
    if(l <= pref[0] && pref[0] <= r) ans++;
    for(int j = 1; j < n ; j++){
        if(l <= pref[j] && pref[j] <= r) ans++;
        ll targetleft = pref[j] - r;
        ll targetright = pref[j] - l;
        ans += mgt.query(0,j,targetleft,targetright);
    }
    cout << ans;

    return 0;
}
