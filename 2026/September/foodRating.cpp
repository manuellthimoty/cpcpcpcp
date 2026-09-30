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

ll gcd(ll a, ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main() {
    GK();

    double X; cin >> X;
    int l,r; cin >> l >> r;
    if(!(l <= X && X <= r)){
        cout << -1;
        return 0;
    }

    ll X_int = (ll)(X * (1000000.0));
    ll d = gcd(X_int,(ll)1e6);
    ll k = 1e6/d;

    ll tot = X_int/d;

    vector<int> res(k,tot/k);
    ll curSum = 0;
    for(auto x : res) curSum += x;
    ll sisa = tot - curSum;
    for(int i = 0 ; i < k ; i++){
        if(sisa == 0) break;
        res[i] ++;
        sisa--;
    }

    cout << k << endl;
    for(auto x : res) cout << x << " ";

    return 0;
}
