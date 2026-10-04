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
    int k; cin >> k;
    vector<ll> c(k);
    for(int i = 0 ; i < k ; i++){
        cin >> c[i];
    }
    for(int i = 0 ; i < k ; i++){
        if(c[i] >=3){
            YES
            return;
        }
    }
    int cnt2 = 0;
    for(int i = 0 ; i < k ; i++){
        if(c[i] >=2){
            cnt2++;
        }
    }
    if(cnt2 >=2){
        YES
    }
    else NO
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
