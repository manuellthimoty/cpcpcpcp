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
    int n,k ; cin >> n >> k;
    string s ;s.resize(n); cin >> s;

    bool oks = true;
    vector<bool> done(n);
    vector<int> cnt1(n,0);
    for(int i = 0 ; i < n ; i++){
        int klmpk = i % k;
        if(s[i] == '1') cnt1[klmpk]++;
    }
    for(int i = 0 ; i < n ; i++){
        // cout << cnt1[i] << endl;
        if(cnt1[i] % 2 != 0){
            oks = false;
            break;
        }
    }
    if(oks) cout << "YES" << endl;
    else cout << "NO" << endl;

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
