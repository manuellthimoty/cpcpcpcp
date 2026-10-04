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
    vector<ll> a(n);input(a,0,n);
    // definisikan mn[i] = min(a[i],a[i+1],...,a[n-1])
    vll mn(n);
    mn[n-1] = a[n-1];
    for(int i = n-2 ; i>=0; i--) mn[i] = min(a[i],mn[i+1]);
    ll tot = 0;
    // banyak blok di indeks i yg tetap itu ada sbnyk mn[i], jd yg gerak = a[i] - mn[i]
    for(int i = 0 ; i < n ; i++) tot += a[i] - mn[i];
    // asumsikan indeks x dikurangi, maka mn[j], untuk j > x ga berubah
    // tapi mn[j] untuk j < x berubah semua sampai ada l < x shg a[l] <= a[x], atau suffix minnya <= 
    // ini terjadi ya waktu ada shifting di mn
    // tot keuntungan yg didapat di kasus ini ya x - m - 1, dmn m kondisi yg td (<=), targetny brti cri x-m terbesar
    
    vector<int> freq(n+1,0);
    for(int i = 0 ; i < n ; i++){
        freq[mn[i]]++;
    }
    ll mx = -1;
    for(auto f : freq) mx = max(mx,1LL*f);
    tot += max(0LL,mx-1);
    cout << tot << endl;
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
