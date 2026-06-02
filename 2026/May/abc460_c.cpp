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
    int n,m ; cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= m ; i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 1;
    int j = 1;
    int cnt = 0;
    while(i <= n && j <= m){
        if(b[j] <= 2 * a[i]){
            i++;
            j++;
            cnt++;
        }
        else{
            i++;
        }
    }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
