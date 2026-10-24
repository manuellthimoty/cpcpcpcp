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
    int a,b; cin >> a >> b;
    if(a <= b){
        cout << -1 << endl;
        return;
    }
    cout << min({b,a-b}) << endl;
    
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
