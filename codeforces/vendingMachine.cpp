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

void solve(int n, int d){
    vector<int> x(n+1);
    for(int i = 1; i <= n ; i++) cin >> x[i];
    ll ans = 0;
    int cur = 1;
    while(cur <= n){
        if(cur == 1){
            ans ++;
            int patokan = cur;
            cur++;
            while(cur <= n && x[patokan] + 2 * d >= x[cur]) cur++;
            continue;
        }
        ans++;
        int patokan = cur;
        cur++;
        while(cur <= n && x[patokan] + 2 * d >=  x[cur]) cur++;
    }
    cout << ans << endl;
}
int main() {
    GK();
    
    while(true){
        int n,d; cin >> n >> d;
        if(n == 0 && d == 0) break;
        solve(n,d);
    }

    return 0;
}
