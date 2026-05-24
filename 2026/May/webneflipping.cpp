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

void solve() {
    int n; 
    cin >> n;
    vector<ll> a(n + 1);
    input(a, 1, n + 1);

    vector<ll> pref_abs(n + 2, 0);
    vector<ll> suff_orig(n + 2, 0);

    ll sum_orig = 0;
    for (int i = 1; i <= n; i++) {
        sum_orig += a[i];
        pref_abs[i] = pref_abs[i - 1] + abs(a[i]);
    }

    for (int i = n; i >= 1; i--) {
        suff_orig[i] = suff_orig[i + 1] + a[i];
    }
    ll max_ans = sum_orig;
    int opt_m = 0;

    for (int m = 1; m <= n; m++) {
        if (a[m] > 0) {
            ll cur = pref_abs[m - 1] - a[m] + suff_orig[m + 1];
            if (cur > max_ans) {
                max_ans = cur;
                opt_m = m;
            }
        }
    }

    vector<int> ans;
    
    if (opt_m > 0) {
        vector<int> pos_k, neg_k;
        int cur_f = 1;
        
        for (int i = opt_m - 1; i >= 1; i--) {
            int target_f = 1;
            if(a[i] > 0){
                target_f = 0;
            }
            if (cur_f != target_f) {
                if (a[i] > 0) pos_k.push_back(i);
                else neg_k.push_back(i);
                cur_f = target_f;
            }
        }
        
        reverse(pos_k.begin(), pos_k.end());
        
        for (int x : pos_k) ans.push_back(x);
        for (int x : neg_k) ans.push_back(x);
        ans.push_back(opt_m);
    }

    cout << ans.size() << endl;
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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