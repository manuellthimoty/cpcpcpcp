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
    ll total = 0;
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        total += a[i];
    }
    if(total % 2 == 1){
        cout << "YES" << endl;
    }
    else{
        if((n * k) % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


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
