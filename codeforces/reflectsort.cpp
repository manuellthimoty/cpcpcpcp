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
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    int n ; cin >> n;
    vint a(n);
    input(a,0,n);
    vint diff(n-1);
    diff[0] = abs(a[1] - a[0]);
    for(int i = 1; i < n-1 ; i++){
        diff[i] = abs(a[i+1]-a[i]);
    }
    ll sum = 0;
    for(int i = 0; i < n -1 ; i++) sum += diff[i];
    int g = diff[0];
    for(int i = 1 ; i < n-1 ; i++) g = gcd(g,diff[i]);
    if(g == 0){
        cout << a[0] << endl;
        return;
    }
    int ans = a[0] % (2 * g);\
    if(ans == 0) ans += 2*g;
    cout << ans + sum << endl;
    
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
