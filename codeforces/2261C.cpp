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
    int e = 0;
    int o = 0;
    for(int i= 0 ; i < n ; i++){
        int x; cin >> x;
        if(x %2 == 0) e++;
        else o++;
    }
    if(o % 2 == 0){
        cout << "Moggity" << endl;
        return;
    }
    if(o > 3){
        cout << "Moggity" << endl;
        return;
    }
    if(o == 3 && e > 0){
        cout << "Moggity" << endl;
        return;
    }
    if(o == 3 && e == 0){
        cout << "Larpity" << endl;
        return;
    }
    if(o == 1){
        if(e == 0){
            cout << "Moggity" << endl;
        }
        else if(e == 1){
            cout << "Larpity" << endl;
        }
        else if( e > 1){
            cout << "Moggity" << endl;
        }
        return;
    }
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
