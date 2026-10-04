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
// bilangan terkecil yg lebih bsr >= x, sebut saja a, shg gcd(a,y-x) !=1 
// jika y -x = genap, maka a = x, jika x genap, dan x + 1 jika x ganjil
// a = x + (x % 2)
// maka jawabannya = x %2
// jika
const int mxA = 1e7;
int spf[mxA + 1];

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int find(int a,int k){
    int ans = a + (k - a % k) % k;
    while(k > 1){
        int curr = spf[k];
        int cek = a + (curr - a % curr) % curr;
        ans = min(ans,cek);
        while(k % curr == 0){
            k = k/curr;
        }
    }
    return ans;
}

int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    int x,y ; cin >> x >> y;
    if(y - x == 1){
        cout << -1 << '\n';
        return;
    }
    if(gcd(x,y) != 1){
        cout << 0 << '\n';
        return;
    }
    if((y-x) % 2 == 0){
        cout << x % 2 << '\n';
        return;
    }
    int cek = find(x,y-x);
    cout << cek - x<< endl;
    // cout << "a" << endl;
    

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    init();
    while (t--) {
        solve();
    }

    return 0;
}
