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
    vector<ll> a(n);
    for(int i =0 ; i < n ; i++) cin >> a[i];
    bool menaik = true;
    for(int i = 0 ; i < n-1 ; i++){
        if(a[i] >= a[i+1]){
            menaik = false;
            break;
        }
    }
    if(menaik){
        cout << "YES" << endl;
        return;
    }
    for(int i = 0 ; i <n-1 ; i++){
        // if(a[i] <=1) continue;
        ll ambil = a[i] -(i+1);
        if(ambil <0){
            cout <<"NO" << endl;
            return;
        }
        a[i] -= ambil;
        a[i+1] += ambil;
    }
    bool oks = true;
    if(a[n-2] < a[n-1]){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
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
