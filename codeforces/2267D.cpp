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
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> pos(n+1);
    for(int i = 0 ; i < n ; i++){
        pos[a[i]] = i+1;
    }
    int acc = 0;
    for(int x = n ; x > 0 ; x--){
        int cur = pos[x] % 2;
        if(cur == 0){
            acc++;
        }
        else acc--;
        if(abs(acc) > 1){
            cout << "NO" << endl;
            return ;
        }

    }
    cout << "YES" << endl;
    return;
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
