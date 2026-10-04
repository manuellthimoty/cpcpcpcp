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


ll computeV(ll n, ll p){
    int cnt = 0;
    int temp = n;
    while(temp % p == 0){
        cnt++;
        temp /= p;
    }
    return cnt;
}

int main() {
    GK();

    int q; cin >> q;
    ll a,b,x,y ; cin >> a >> b >> x >> y;
    ll v5a=computeV(a,5);
    ll v5b = computeV(b,5);
    ll v5x = computeV(x,5);
    ll v5y = computeV(y,5);


    ll v2a=computeV(a,2);
    ll v2b = computeV(b,2);
    ll v2x = computeV(x,2);
    ll v2y = computeV(y,2);

    while(q--){
        ll r,c,h,w,k ; cin >> r >> c >> h >> w >> k;
        ll rhs5 = k - v5a - v5b;
        ll rhs2 = k - v2a - v2b;

        ll ans = 0;
        
        for(ll i = r ; i < r + h;i++){
            ll bound1 = -1;
            ll num5 = rhs5 - i * v5x;
            if(v5y == 0){
                if(num5 >= 0) bound1 = c + w - 1;
            } else {
                if(num5 >= 0) bound1 = num5 / v5y;
            }

            ll bound2 = -1;
            ll num2 = rhs2 - i * v2x;
            if(v2y == 0){
                if(num2 >= 0) bound2 = c + w - 1;
            } else {
                if(num2 >= 0) bound2 = num2 / v2y;
            }

            ll max_bound = max(bound1, bound2);
            
            ll final_bound = min(c + w - 1, max_bound);

            if (final_bound >= c) {
                ans += (final_bound - c + 1);
            }
        }
        cout << ans << '\n';
    }

    

    

    return 0;
}
