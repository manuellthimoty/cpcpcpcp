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
    vector<int> a(n+1,0);
    for(int i = 1 ; i<= n ; i++) cin >> a[i];
    vector<ll> pref(n+1,0);
    for(int i = 1; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    int q; cin >> q;
    vector<ll> T(n+1,0);
    for(int i = 1; i <= n ; i++){
        T[1] += pref[i];
    }
    for(int i = 1 ; i < n ; i++) T[i+1] = T[i] - a[i] * (n-i+1);
    vector<ll> prefT(n+1,0);
    for(int i = 1; i <= n ; i++) prefT[i] = prefT[i-1] + T[i];

    auto locate = [&] (ll idx){
        auto pref = [&](ll i) -> ll {
            return (ll)i * (2 * (ll)n - i + 1) / 2;
        };
        ll l = 1, r = n;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (pref(mid) >= idx)
                r = mid;
            else
                l = mid + 1;
        }

        ll i = l;
        ll offset = (ll)((ll)idx - pref(i - 1));
        ll j = (i - 1) + offset;
        pair<ll,ll> ans = {i,j};
        return ans;
    };

    vector<ll> prefP(n+1,0);
    for(int i = 1; i <= n ; i++) prefP[i] = prefP[i-1] + pref[i];

    auto solve = [&](ll left, ll right){
        pair<ll,ll> leftc = locate(left);
        pair<ll,ll> rightc = locate(right);
        ll li = leftc.first;
        ll lj = leftc.second;
        ll ri = rightc.first;
        ll rj = rightc.second;
        if(li == ri){
            ll ans = prefP[rj] - prefP[lj-1];
            ans -= (rj-lj+1) * pref[li-1];
            return ans;

        }
        ll ans = 0;
        // ans += prefT[n] - prefT[lj-1];
        // ans -= pref[li-1] * (n-lj+1);
        // ans += prefT[ri-1] - prefT[li];
        // ans += prefT[rj] - prefT[ri-1] - (rj - ri+1) * pref[ri-1];
        ans += prefP[n] - prefP[lj-1];
        ans -= pref[li-1] * (n-lj+1);
        ans += prefT[ri-1] - prefT[li];
        ans += prefP[rj] - prefP[ri-1];
        ans -= (rj-ri+1) * pref[ri-1];


        return ans;
    };
    while(q--){
        ll l,r; cin >> l >> r;
        cout << solve(l,r) << '\n';
        // pair<ll,ll> idx1 = locate(l);
        // pair<ll,ll> idx2 = locate(r);
        // cout << idx1.first << " " << idx1.second << " ";
        // cout << idx2.first << " " << idx2.second << " ";
        // cout << endl;    }
    }
    return 0;
}
