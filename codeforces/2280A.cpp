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
    int k ; cin >> k;
    int cnta = 0, cntb= 0;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        if(x % 2 ==1 ) cnta++;
    }
    for(int i = 0 ;i < n ; i++){
        int x; cin >> x;
        if(x %2 == 1) cntb++;
    }
    if(k %2 == 1){
        if(cnta <= cntb){
            cout << "YES" ;
        }
        else cout << "NO";
    }
    else{
        if(cnta >= cntb){
            cout << "YES";
        }
        else cout << "NO";
    }
    cout << endl;
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
