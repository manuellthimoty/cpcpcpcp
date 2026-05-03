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

ll gcd(ll a,ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    ll n ; cin >> n;
    vector<ll> v;
    for(ll i = 1; i <= n-1 ; i++){
        if(gcd(i,n) == 1){
            v.push_back(i);
        }
    }
    ll prod = 1;
    for(auto val : v){
        prod = (prod * val ) % n;
    }
    // jika hasil a1*a2*...*ak = 1 mod N, maka kita selesai, jika tidak, misalkan saja
    // a1*a2*...*ak = M mod N, tinjau bahwa krn gcd(ai,N) = 1, haruslah gcd(M,N) = 1 dan
    // M <= N-1. jadi M ada di antara a1,a2,...,ak tgl coret 1 biji itu deh
    if(prod == 1){
        cout << v.size() << endl;
        for(auto val : v) cout << val << " ";
    }
    else{
        cout << v.size() -1 << endl;
        for(auto val : v){
            if(prod == val) continue;
            cout << val << " ";
        }
    }
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
