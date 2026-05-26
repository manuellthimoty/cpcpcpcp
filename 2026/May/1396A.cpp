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

// tinjau bahwa jika a1,a2,..,an semuanya habis dibagi n, maka hasilnya pasti 0
// bisakah kita buat supaya a + p * (n-1) habis dibagi n? 
// a + pn - p, maka a - p habis dibagi n
// maka p = a kongruen n

void solve(){
    ll n ; cin >> n;
    vector<ll> a(n+1);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    vector<ll> first,second,third;
    for(ll i = 1 ; i <= n-1 ; i++){
        ll p = a[i] % n;
        a[i] = a[i] + p * (n-1);
        first.push_back(p * (n-1));
    }
    if(n == 1){
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 <<" " <<1 <<  endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << -1* a[1] << endl;
        return;
    }
    // n membagi a - (a % n)
    // a = a % n (mod n)
    ll lastP = a[n] % n;
    second.push_back(-lastP);
    a[n] = a[n] - lastP;
    for(ll i = 1 ; i <= n ; i++){
        third.push_back(-1*a[i]);
    }
    cout << 1 << " " << n-1 << endl;
    for(auto a : first){
        cout << a << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << -1*lastP << endl;
    cout << 1 << " " << n << endl;
    for(auto t : third){
        cout << t << " ";
    }
    cout << endl;
    
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
