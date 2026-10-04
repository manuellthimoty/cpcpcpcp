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

    ll n ; cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n == 2){
        cout << 2;
        return 0;
    }

    if(n == 3){
        cout << 6;
        return 0;
    }
    if(n % 2 == 1){
        cout << (ll) n * (n-1) * (n-2);
        return 0;
    }
    if(n % 3 != 0){
        ll ans = n * (n-1) * (n-3);
        ans = max(ans, (n-1) * (n-2) * (n-3));
        cout << ans;
    }
    else{
        ll ans = n * (n-1) * (n-5);
        ans = max(ans, (n-1) * (n-2) * (n-3));
        cout << ans;
    }
    return 0;
}
