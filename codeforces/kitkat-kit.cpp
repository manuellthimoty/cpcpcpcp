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
    int a,b,x,y; cin >> a >> b >> x >> y;
    if(x < y){
        int first = y-x;
        int second = max(b - first,a);
        cout << first + second << endl;
        return;
    }
    else if(x > y){
        int first = x;
        int second = max(b-y,a-x);
        cout << first + second << endl;
        return;
    }
    else{
        cout << max(a,b) << endl;
        return;
    }
    

}


int main() {
    GK();

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
