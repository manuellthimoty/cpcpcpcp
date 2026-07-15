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
const int mxA = 2e6;
int spf[mxA + 1];
vector<int> R(mxA+1);
vector<ll> cnt(mxA+1,0);
vector<ll> ans(mxA+1,0);
ll modpow(ll a, ll e) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a;
        a = a * a;
        e >>= 1;
    }
    return r;
}

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    for(int i = 1 ; i <= mxA ; i++){
        int cur = i;
        int final = 1;
        while(cur > 1){
            int cur_prime = spf[cur];
            int cnt = 0;
            while(cur % cur_prime == 0){
                cur /= cur_prime;
                cnt++;
            }
            final = final * modpow(cur_prime,(cnt+1)/2);
        }
        R[i] = final;

    }
    for(int d = 1 ; d <= mxA; d++){
        for(int a = R[d] ; ; a += R[d]){
            ll b = a+d;
            if(b > mxA) break;
            cnt[b]++;
        }
    }
    for(int i = 1; i <= mxA ; i++){
        ans[i] = ans[i-1] + cnt[i];
    }   
}
void solve(){
    int n ; cin >> n;
    cout << ans[n] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
