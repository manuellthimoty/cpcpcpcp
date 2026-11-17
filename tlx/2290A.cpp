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

void solve(){
    int n; cin >> n;
    vector<ll> b(n+1);
    for(int i =1 ; i <= n ; i++) cin >> b[i];
    ll tot = 0;
    for(int i = 1 ; i <= n ; i++) tot += b[i];
    if(tot != 0){
        cout << -1 << endl;
        return;
    }
    vector<int> cnt(n+1,0);
    vector<int> a(n+1,0);
    vector<int> is(n+1);
    bool ok = true;
    for(int i = 1; i <= n ; i++){
        int j = b[i] + n - (i-1);
        if(j < 1 || j > n){
            ok = false;
            break;
        }
        cnt[j]++;
        a[j] = i;
    }
    for(int i = 1; i <= n ; i++){
        if(cnt[i] != 1){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    for(int i =1 ; i <= n ; i++) cout << a[i] << " ";
    cout << endl;

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
