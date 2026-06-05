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
    vector<int> c(n);
    for(int i = 0 ; i < n ; i++) cin >> c[i];
    ll total = 0;
    ll totOnes = 0;
    if(n == 1){
        if(c[0] < 3){
            cout << 0 << endl;
            return;
        }
        else{
            cout << c[0] << endl;
            return;
        }
    }
    for(auto d : c){
        if(d > 1) total += d;
        if(d == 1) totOnes ++ ;
    }
    if(total < 2){
        cout << 0 << endl;
        return;
    }
    ll allowed = 0;
    for(auto d : c){
        if(d > 1){
            allowed += (d/2) - 1;
        }
    }
    if(totOnes == (n-1)){
        allowed = (total)/2;
    }
    total += min(totOnes,allowed);
    cout << total << endl;
    
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
