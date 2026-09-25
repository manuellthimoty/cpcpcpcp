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

void solve(){
    ll s,k ; cin >> s >> k;
    if(k == 1){
        cout << s << endl;
        return;
    }
    if(s == 1){
        if(k == 1){
            cout << 1 << endl;
            return;
        }
        if(k % 2 == 0){
            cout << 1 << endl;
            return;;
        }
        else{
            cout << (k+1)/2 << endl;
            return;
        }
    }

    ll len_cols = 2 * s -1;
    ll b = (k/len_cols) +1;
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
