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

//r^2 <= x^2 + y^2 < (r+1)^2
// for x = k, (from x = -r, r)
// r^2 <= k^2 + y^2 < (r+1)^2
ll is_squared(ll n){
    return (ll)sqrt(n) * (ll)sqrt(n) == n;
}
// r= 3,
// 9 <= x^2 + y^2 < 4^2
// 9 - k^2 <= y^2 < 16 - k^2
// k = -3,
// 0 <=y^2 <7 -> y = 0,1,2, -1,-2
// k = -2,
// 5 <= y^2 < 12, y =3,
// 2,2 <= y < 3..
// y = 3 <= 3


ll compute(ll r){
    ll ans = 0;
    for(ll k = -r; k <=r ; k++){
        ll left = (r * r - k * k);
        ll right = (r+1) * (r+1) - k * k;
        
        ll final_left = (ll) sqrt(left);
        ll final_right = (ll) sqrt(right);
        
        if(!is_squared(left)){
            final_left++;
        }
        if(is_squared(right)){
            final_right--;
        }
        
        ans += max(0LL,final_right - final_left + 1) * 2;
        if(left == 0){
            ans--;
        }
    }
    return ans;
}

void solve(){
    int r ; cin >> r;
    cout << compute(r) << '\n';
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
