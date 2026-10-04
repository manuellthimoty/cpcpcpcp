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

void solve(){
    int n ; cin >> n; int x ; cin >> x;
    vint a(n); input(a,0,n);
    sort(a.begin(),a.end()); reverse(a.begin(),a.end());
    vint mn(n);
    mn[0] = a[0];
    for(int i = 1; i < n ;i++){
        mn[i] = min(mn[i-1],a[i]);
    }
    int cnt = 0;
    int curlen = 1;
    for(int i = 0 ; i < n ; i++){
        if(curlen * mn[i] >= x){
            cnt++;
            curlen = 1;
        }
        else{
            curlen++;
        }
    }
    cout << cnt << endl;
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
