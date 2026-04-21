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

int ans =0;

void run(int i, int n, double before, int count,vector<double>& a){
    if(i == n){
        ans = max(ans, count);
        return;
    }
    // proses simbol ke i
    // jika pada i kita pilih ke kanan
    if(before * (before + a[i]) <= 0) run(i+1,n,before + a[i],count+1,a);
    else run(i+1,n,before + a[i],count,a);

    if(before * (before -a[i]) <= 0) run(i+1,n,before - a[i],count+1,a);
    else run(i+1,n,before-a[i],count,a);
}

void solve(){
    int n ; cin >> n;
    vector<double> l(n);
    for(int i = 0 ; i < n ; i++){
        cin >> l[i];
    }
    run(0,n,0.5,0,l);
    cout << ans << endl;

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
