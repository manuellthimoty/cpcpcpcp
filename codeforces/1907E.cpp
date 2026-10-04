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
// untuk fix d(a),d(b),d(c),
// kita cari shg a + b + c = n
// d(a) = a mod 9
// a = 9p + d(a), 
// b = 9q + d(b)
// c = 9r + d(c) 
// 9(p + q + r) + d(n) = n
// 9(p+q+r) = n - d(n)
// p + q + r = (n-d(n))/9
int digsum(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n/=10;
    }
    return sum;
}

void solve(){
    int n; cin >> n;
    int rhs1 = (n - digsum(n))/9;
    ll cnt1 = ((rhs1+1) * (rhs1+2))/2;
    ll cnt2 = ((digsum(n)+1) * (digsum(n)+2))/2;
    cout << cnt1 * cnt2 << endl;
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
