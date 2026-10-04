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
    int n; cin >> n;
    int a = n/100;
    n -= a * 100;

    int b = n/20;
    n -= 20 * b;


    int c = n/10;
    n -= 10 * c;


    int d = n/5;
    n -= 5*d;

    int e = n;
    n-=e;

    cout << a + b + c + d + e << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
