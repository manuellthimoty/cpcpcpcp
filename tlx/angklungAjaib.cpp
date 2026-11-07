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

int main() {
    GK();
    ll n,t,k; cin >> n >> t >> k;
    ll ans = 0;
    for(int i = 1; i <= n ; i++){
        ll cnt = 0;
        for(int j = 1; j * j <= i ; j++){
            if(i % j == 0){
                if(j <= t) cnt++;
                if(i/j != j && i/j <= t) cnt++;
            }
        }
        cnt += (t/i) - (i <= t);
        if(cnt <= k) ans++;
    }
    
    cout << ans;
}
