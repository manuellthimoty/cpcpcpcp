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

bool isprime(ll n){
    for(int i = 2; i * i <= n ; i++){
        if(n % i == 0) return false;
    }
    return true;
}
void solve(){
    while(true){
        for(int left : {3,5,7}){
            for(int right : {3,7}){}
        }
    }
    // cout << isprime(n);
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
