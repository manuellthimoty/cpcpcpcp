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
    vint a(n); input(a,0,n);
    vector<bool> isdiv6(n,false);
    for(int i = 0 ; i < n ; i++){
        if(a[i] % 6 == 0) isdiv6[i] = true;
    }
    vector<int> ans;
    for(int i = 0 ; i < n ; i ++){
        if(isdiv6[i]) ans.push_back(a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] % 2 == 0 && !isdiv6[i]) ans.push_back(a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] % 2 != 0 && a[i] % 3 != 0) ans.push_back(a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] % 3 == 0 && !isdiv6[i]) ans.push_back(a[i]);
    }
    for(auto a : ans) cout << a << " ";
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
