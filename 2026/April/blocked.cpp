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
    int n ; cin >> n ;
    // map<int,int> freq;
    vint a(n);
    input(a,0,n);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int ans = true;
    for(int i = 1 ; i < n ; i++){
        if(a[i] == a[i-1]){
            ans = false;
        }
    }
    if(ans){
        for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
        cout << endl;
    }
    else cout << -1 << endl;
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
