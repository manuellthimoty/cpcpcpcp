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
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    if(a[0] == 0 && a[n-1] == 0){
        cout << 0 << endl;
        return;
    }
    int cnt0 = 0;
    for(int i = 0; i < n ; i++){
        if(a[i] == 0) cnt0++;
    }
    if(cnt0 < 2){
        cout << -1 << endl;
        return;
    }
    if(a[0] == 0 || a[n-1] == 0){
        cout << 1 << endl;
    }
    else cout << 2 << endl;
    
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
