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

ll lcm(ll a, ll b){
    return (a/gcd(a,b)) * b;
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n+1);
    for(ll i = 1 ; i<= n ; i++) cin >> a[i];
    vector<ll> d(n+1);
    for(int i = 1; i <= n ; i++){
        ll cur = 1;
        for(int j = 1; j <= n ; j++){
            if(i == j) continue;
            if(a[i] == a[j]){
                cout << "NO" << endl;
                return;
            }
            cur = lcm(cur,abs(a[i] - a[j]));
        }
        d[i] = cur;
    }
    // cout << "INFO";
    bool oks = true;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            if(i == j) continue;
            if(abs(a[i] - a[j]) % gcd(d[i],d[j]) !=0){
                oks = false;
                break;
            }
        }
    }
    if(oks){
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
