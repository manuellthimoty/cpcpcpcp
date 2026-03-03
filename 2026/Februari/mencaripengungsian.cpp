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
    int n,q ; cin >> n >> q;
    vll a(n);
    input(a,0,n);
    sort(a.begin(),a.end());
    vector<ll> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n ; i++) pref[i] = pref[i-1] + a[i];
    while(q--){
        ll l,r ; cin >> l >> r;
        ll left = lower_bound(a.begin(),a.end(),l) - a.begin();
        ll right = upper_bound(a.begin(),a.end(),r) - a.begin();
        ll left_score = 0;
        if(left > 0){
            left_score = l * left - pref[left-1]; 
        }

        ll right_score = 0;
        if(right < n){
            right_score = (pref[n-1] - (right > 0 ? pref[right-1] : 0)) - r * (n - right);
        }
        cout << left_score + right_score << endl; 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
