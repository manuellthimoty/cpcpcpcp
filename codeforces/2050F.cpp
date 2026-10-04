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
const int MAXN = 200005; // Ukuran maksimum array
const int MAXLOG = 20;   // 2^20 sekitar 1 juta, cukup untuk panjang array pada umumnya

int st[MAXN][MAXLOG];
int arr[MAXN];

void buildSparseTable(int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            st[i][j] = std::gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int queryGCD(int L, int R) {
    int len = R - L + 1;
    int k = __lg(len); 
    return std::gcd(st[L][k], st[R - (1 << k) + 1][k]);
}


void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n-1 ; i++){
        arr[i] = abs(a[i] - a[i+1]);
    }
    if (n > 1) buildSparseTable(n-1);
    // cout << "arr : ";
    // for(int i = 0 ; i < n -1 ; i++){
    //     cout << arr[i] << " ";
    // }

    // arr[i] = a[i] - a[i+1]
    // a[l] - a[l+1], a[l+1] - a[l+2] ,..,a[r-1] - a[r]
    // arr[l] , arr[l+1], arr[r-1]
    while(q--){
        int l,r; cin >> l >> r;
        
        l--; r--;
        if(l == r){
            cout << 0 << " ";
            continue;
        }
        r--;
        cout << queryGCD(l,r) << " ";
    }
    cout << endl;
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
