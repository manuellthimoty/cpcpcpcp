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

__int128 modpow(__int128 a, __int128 e) {
    __int128 r = 1;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a;
        a = (__int128)a * a;
        e >>= 1;    
    }
    return r;
}

__int128 len(__int128 n){
    __int128 cnt = 0;
    while(n > 0){
        cnt++;
        n = n/10;
    }
    return cnt;
}

void solve(){
    int cnt = 0;
    for(int a = 1; a <= 9 ; a++){
        for(int p = 1 ; p <= 25 ; p++){
            __int128 rhs = modpow(a,p);
            if(len(rhs) == p){
                // print __int128
                cnt++;
                __int128 v = rhs;
                if (v == 0) {
                    cout << 0 << '\n';
                } else {
                    bool neg = false;
                    if (v < 0) { neg = true; v = -v; }
                    string s;
                    while (v > 0) {
                        int digit = (int)(v % 10);
                        s.push_back('0' + digit);
                        v /= 10;
                    }
                    if (neg) s.push_back('-');
                    reverse(s.begin(), s.end());
                    cout << s << '\n';
                }
            }
        }
    }
    cout << cnt << endl;
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
