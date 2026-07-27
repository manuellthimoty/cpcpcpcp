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
    vector<ll> a(n),b(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }   
    for(int i = 0 ; i < n ; i++){
        cin >> b[i];
    }

    for(int i = n-1 ; i>= 1 ; i--){
        if(a[i] <= b[i]) continue;
        // a[i] > b[i]
        ll selisih = a[i] - b[i];
        a[i] = b[i];
        if(i > 0) a[i-1] = a[i-1] + selisih;
    }
    

    if(a[0] <= b[0]){
        cout << "YES" << endl;
    }
    
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
