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

// 1 1 1 2 2 3
// 1 2 3 4 
void solve(){
    int n ; cin >> n;
    int len = (n * (n-1))/2;
    vector<int> b(len);
    for(int i = 0 ; i < len ; i++) cin >> b[i];
    sort(b.begin(),b.end());
    int k =n;
    for(int i = 0 ; i < len ; i += k ){
        cout << b[i] << " ";
        k--;
    }
    cout << 1000000000;
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
