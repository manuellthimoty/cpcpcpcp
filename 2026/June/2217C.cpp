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

int gcd(int a, int b){
    if( a== 0) return b;
    if( b == 0 ) return a;
    return gcd(b, a % b);
}

void solve(){
    int n,m,a,b ; cin >> n >> m >> a >> b;
    if(gcd(b,m) != 1 | gcd(a,n) != 1){
        cout << "NO" << endl;
        return;
    }
    if(gcd(m,n) < 3){
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
