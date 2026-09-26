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

const int mxA = 3e5;
int spf[mxA + 1];

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}


void solve(){
    int n,x; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n ; i++) cin >> a[i];
    if(x == 1){
        cout << 0 << endl;
        return;
    }
    
    map<ll,ll> cnt;
    set<ll> primes_x;
    int curx = x;
    // cout << "curx " << x << endl;
    while(curx > 1){
        int curPrimex = spf[curx];
        primes_x.insert(curPrimex);
        while(curx % curPrimex == 0){
            curx /= curPrimex;
        }
    }
  
    // for(auto p : primes_x) cout << p << " ";
    // cout << endl;
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        while(cur > 1){
            int curPrime = spf[cur];
            cnt[curPrime] += a[i];
            while(cur % curPrime == 0) cur /= curPrime;
        }
    }
    ll ans = 0;
    for(auto c : cnt){
        auto it = primes_x.find(c.first);
        if(it != primes_x.end()){
            ans = max(ans,c.second);
        }
    }
    cout << ans << endl;
}
int main() {
    GK();

    int t;
    cin >> t;

    init();
    while (t--) {
        solve();
    }

    // cout << spf[4] <<endl;

    return 0;
}
