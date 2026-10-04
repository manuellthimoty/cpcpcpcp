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


// p[i] = a[1] ^ a[2] ^ a[3] .. ^ a[i]
// f(x,y) = p[y] ^ p[x-1]
//  1 ^ 0 ^ 2 ^ 3 ^ 7 ^ 8
//  1 ^ 0
// 0 ^ 0 ^ 2 ^ 3 ^ 8 = 0
// pref[y] ^ pref[x-1] = 0
// pref[y] = pref[x-1]
// pref[i] ^ pref[i-1] = a[i]
void solve(){
    
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
