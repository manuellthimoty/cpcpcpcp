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

int cnt1(int mask){
    bitset<3> s(mask);
    int cnt = 0;
    for(int i = 0 ; i <3 ; i++){
        if(s[i]) cnt++;
    }
    return cnt;
}

void solve(){
    int n ;cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    // vector<vector<vector<ll>>> dp(3*n+5,vector<vector<ll>>(8,vector<ll>(3)));
    vector<array<array<ll,3>,8>> dp(3*n+1);
    vector<bool> ada(3*n+5,false);
    for(int i = 1; i <= n ; i++){
        ada[a[i]] = true;
    }
    ll MOD = 998244353;
    dp[a[n]][0][0] = 1;
    for(int x = a[n] ; x >= 1 ; x--){
        for(int mask = 0 ; mask <= 7 ; mask++){
            for(int c = 0 ; c <= 2 ; c++){
                int newmask = (mask << 1);
                newmask &= 7;
                dp[x-1][newmask][c] += dp[x][mask][c];
                dp[x-1][newmask][c] %= MOD;
                if(ada[x]){
                    newmask = ((mask << 1) & 7) | 1;
                    int newc = c;
                    if(cnt1(mask) != 2){
                        newc++;
                    }
                    if(newc <= 2){
                        dp[x-1][newmask][newc] += dp[x][mask][c];
                        dp[x-1][newmask][newc] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int mask = 0 ; mask <= 7 ; mask++){
        for(int c = 0 ; c <= 2; c++){
            ans += dp[0][mask][c];
            ans %= MOD;
        }
    }
    ans --;
    ans += MOD;
    ans %= MOD;
    cout << ans << endl;
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
