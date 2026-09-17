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

    int n, k; cin >> n >> k;
    vint a(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a.begin()+1,a.end());
    
    int ans = a[k];
    if(k == 0){
        if(a[1] > 1){
            cout << a[1] - 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
        return 0;
    }
    if(k+1 <= n && ans == a[k+1]){
        cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0;
}
