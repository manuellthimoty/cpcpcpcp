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
    int n, m ; cin >> n >> m;
    // if(n == 1){
    //     cout << 1 << endl;
    //     return;
    // }
    vector<int> a(m);
    for(int i = 0 ; i < m ; i++) cin >> a[i];
    int loc1 = -1;
    for(int i = 0 ;i < m ; i++){
        if(a[i] == 1){
            loc1 = i+1;
        }
    }
    if(loc1 > 1){
        cout << 1 << endl;
        return;
    }
    if(m == 2 && a[0] == 1 && a[1] == 1){
        cout << 1 << '\n';
        return;
    }

    if(loc1 <= 1){
        int last = a[m-1];
        // 1,2,...,k itu ada di sub array ke k, k+1,...,n -> ada (n-k+1)
        cout << max(0,n- last +1) << endl;
        return;
    }
    // if(loc1 == 0){
    //     int first= a[0];
    //     int last = a[m-1];
    //     // x, x+1,..., k ada di 
    // }

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
