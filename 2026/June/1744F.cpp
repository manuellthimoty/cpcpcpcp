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
    vector<int> p(n);
    for(int i = 0 ; i < n ; i++) cin >> p[i];
    // notice that there must be 0 at l,r
    // let p[k] 0, then
    // we cannot choose l,r from k+1,k+2,..,n  or 1,2,..,k-1
    // assume we start at 0. and let p[m] =1, l = r = k
    // if m > k, then expanding l to left (anything) and expanding r to k-1
    // wont change the mex (still 0)
    // and if we want the mex equal to two, then mex before MUST be equal to 1 first. 
    // example : 3 7 2 6 0 1 5 4
    // ans : 15
    // misal 0 1 diambil, mexnya kan 2
    // berari med nya <= 1, mednya antara 0 atau 1, padhal kalo dipilih kan 
    // 0 1 a b c d disini mednya b > 1 kontradiksi
    // 0 1 a, disini mednya 1
    // 0 1 a b, disini mednya 1
    // jadi misal kita ambil 0,1,...,x-1, maka mexnya = x
    // dan kalo diurutin 0,1,..,x-1, ini ada sebanyak x
    // misalkan ada k anggota yang >=x, 
    // 0,1,...,x-1,a1,a2,..,ak -> total = x + k anggota
    // nilai tengahntya berarti floor ((x + k + 1)/2), kita mau supaya
    // nilai dari ini <= x. berarti floor(x + k + 1)/2 <= x. 
    // maka knya maks x, jadi k <= x. 

    // jadi, kalo 0,1,..,x-1 ikut, maka maksimal anggota diantara itu (tambahan)cuman boleh 
    // x anggota. 
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
