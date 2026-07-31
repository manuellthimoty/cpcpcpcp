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
const int mxA= 5e5;
int spf[mxA + 1];
vector<ll> s(5e5+1,0);

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
    vector<int> active;
    vector<int> a(n);
    for(int i = 0; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n; i++){
        int cur = a[i];
        while(cur > 1){
            int curFac = spf[cur];
            int cntF = 0;
            while(cur % curFac == 0){
                cur = cur/curFac;
                cntF++;
            }
            if(s[curFac] == 0){
                active.push_back(curFac);
            }
            s[curFac] += cntF;
        }
    }
    int MOD = 1e9+7;
    ll ans = 1;
    for(auto i : active){
        if(spf[i] != i) continue;
        ans = ans * (s[i] +1);
        ans %= MOD;
        s[i] = 0;
    }
    cout << ans << endl;
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
