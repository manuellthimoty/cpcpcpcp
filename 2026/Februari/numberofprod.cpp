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
    ll n ; cin >> n;
    vll a(n); input(a,0,n);
    vll cntpos(n,0), cntneg(n,0);
    ll total = (n * (n+1))/2;
    if(a[0] > 0){
        cntpos[0] = 1;
    }
    else{
        cntneg[0] = 1;
    }
    for(ll i = 1 ; i < n ; i++){
        cntpos[i] = cntpos[i-1];
        cntneg[i] = cntneg[i-1];
        if(a[i] < 0) cntneg[i]++;
        else cntpos[i]++;
        cntneg[i] %=2 ;
    }
    ll cntOddNeg = 0;
    ll cntEvenNeg = 1;
    ll ans1 = 0;
    for(ll i =0 ; i < n ; i++){
        if(cntneg[i] % 2 == 1){
            cntOddNeg++;
            ans1+= cntEvenNeg;
        }
        else{
            cntEvenNeg++;
            ans1 += cntOddNeg;
        }
    }

    cout << ans1 << " " << total - ans1 << endl;
    // negative : al * al+1 * .. * ar <0
    // banyak bil negatif : ganjil
    // cntneg[j] - cntneg[i-1] = 1 mod 2
    
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
