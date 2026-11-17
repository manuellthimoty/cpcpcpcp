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

ll ask(int l, int r){

    cout << "? " << l << " " << r << endl;

    ll res;
    if(!(cin >> res)) exit(0);
    return res;
}

void answer(string ans){
    cout << "! " << ans << endl;
}

void solve(){
    int n ; cin >> n;
    ll k = ask(1,n);
    if(k == 0 || k == n){
        answer("NO");
        return;
    }
    ll final = ask(1,k);
    if(final == k){
        answer("NO");
    }
    else answer("YES");
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
