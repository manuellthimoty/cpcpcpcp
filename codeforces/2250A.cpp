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
    int n ; cin >> n;
    vector<int> a(n+1);

    // k < w[1], k > w[2] ->w[2] <  k < w[1]
    // at i = 2m+1, must move to right -> w[2m-1] > k
    // at i = 2m, must move to left -> w[2m] < k -> w[2m] < k < w[2m-1]
    // thereforef max(w[2],w[4],...) < k < min(w[1],w[3]...)
    for(int i = 1; i <= n ; i++) cin >> a[i];
    if(n == 1) {
        cout << "NO" << endl;
        return;
    }
    int left = a[2];
    int right = a[1];
    for(int i = 3; i <= n ; i++){
        if(i % 2 == 1){
            right = min(right,a[i]);
        }
        else left = max(left,a[i]);
    }
    
    if(right > left+1) cout << "YES" << '\n';
    else {cout << "NO" << '\n';}
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
