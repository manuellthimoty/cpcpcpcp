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
    ll n;
    cin >> n;
    vector<int> a(n);
    input(a,0,n);
    // ai * aj = j - i
    // i = j + ai * aj;
    ll count = 0;
    ll limit = sqrt(n);
    set<pair<int,int>> st;
    for(ll val = 1 ; val <= limit ; val++){
        for(ll j = 0 ; j < n ; j++){
            ll len = a[j] * val;
            ll i = j - len;
            if(i >= n || i < 0) continue;
            if(a[i] == val){
                // st.insert(make_pair(i,j));
                count++;
            }
        }
    }

    for(ll val = 1 ; val * val <= n ; val++){
        for(ll i = 0 ; i < n ; i++){
            ll len = a[i] * val;
            ll j = i + len;
            if(j >= n || j < 0) continue;
            if(a[j] == val){
                // st.insert(make_pair(i,j));
                if(a[i] > limit){
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    // cout << st.size() << endl;
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
