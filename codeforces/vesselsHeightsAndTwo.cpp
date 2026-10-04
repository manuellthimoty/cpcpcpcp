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
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a.rbegin(),a.rend());
    bool oks = true;
    for(int i = 0 ; i < n-2 ; i++){
        if(a[i] % a[i+1] != a[i+2]){
            oks = false;
            break;
        }
    }
    if(!oks){
        cout << -1 << endl;
        return;
    }
    for(int i = 0 ; i < 2; i++) cout << a[i] << " ";
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
