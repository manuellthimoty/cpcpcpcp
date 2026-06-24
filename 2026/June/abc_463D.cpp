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
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<ll> pref_even(n);
    vector<ll> pref_odd(n);
    pref_even[0] = a[0];
    pref_odd[0] = 0;
    pref_odd[0] = 0;
    for(int i = 1 ; i < n ; i++){
        if(i % 2 == 1){
            pref_odd[i] = pref_odd[i-1] + a[i];
            pref_even[i] = pref_even[i-1];
        }
        else{
            pref_even[i] = pref_even[i-1] + a[i];
            pref_odd[i] = pref_odd[i-1];
        }
    }
    // tinjau bahwa misal a1 a2 a3 a4 a5 a6 di reverse jadi a6 a5 a4 a3 a2 a1 -> sum_even = a5 + a3 + 1 = sum_odd. jadi, kalo beda paritas, sum_even baru = sum _dd
    // jadi, misal total = S, maka yg baru S' = S - sum_even_lama + sum_even baru.
    // kalo paritasnya sama, skip. jadi , kita mau cari , l ,r shg sum_odd(l,r) - sum_even(l,r) maksimum
    // sum_odd(l,r) = pref_odd(r) - prewf_odd(l-1)
    // sum_even(l,r) = pref_even(r) - pref_even(l-1)
    // dikurangi = pref_odd(r) - pref_even(r) + pref_even(l-1) - pref_odd(l-1)
    // jika r genap -> pref_odd
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
