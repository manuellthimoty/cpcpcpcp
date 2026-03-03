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
    int n,k,l ; cin >> n >> k >> l;
    vector<int> a(n+1);
    input(a,1,n+1);
    sort(a.begin(),a.end());
    vector<int> d(n+1);
    for(int i = 1; i < n ; i++){
        d[i] = a[i+1] - a[i];
    }
    d[0] = a[1];
    d[n] = l - a[n-1];
    int time = max(d[0],d[n]);
    int mxidx;
    if(time == d[0]) mxidx = 0;
    else mxidx = n;
    for(int i = 1; i < n ; i++){
        if(d[i]/2 > time){
            time = d[i]/2;
            mxidx = i;
        }
    }
    int ans = 0;
    if (mxidx != 0 && mxidx != n){  
        ans += time;// sisa : k-1, posisi : 0 -> a[1] + t, n -> a[n] - t;
        // pindah ke 0, waktu : a[1] + t; sisa : k -2, posisi : 0->0, n-> a[n]-t-(a[1]-t);
        // pindah ke n, waktu : l - a[n] + a[1] + 2 * t, posisi : 0->  
    }

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
