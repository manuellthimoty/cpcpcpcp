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


//    1
//   10
//   11
// ....
//  111
// ....
// 1111
//
//11111 (panjang n)
// 

string convert(int n, int mxSz){
    string s;
    while(n > 0){
        if(n % 2 == 1){
            s += '1';
        }
        else s += '0';
        n = n/2;
    }
    while(s.size() < mxSz){
        s += '0';
    }
    reverse(s.begin(),s.end());
    return s;
}
//   1
//  10
//  11
// 100
//1010
//1110
// 
void solve(){
    int n ; cin >> n;
    ll k = 1;
    for(int i = 2; i <= n ; i++) k = k | i;
    ll m = 1;
    for(ll i = 2; i < n ; i++){
        m = m ^ i;
    }
    m ^= 2 * n;
    int len = 1;
    ll pw = 1;
    while(pw <= n){
        pw *= 2;
        len++;
    }
    // cout << m << endl;
    // 101110
    vector<int> mark(n+1,0);
    mark[n] = 1;
    string sm = convert(m,len+1);
    // cout << sm << endl;
    for(int i = 1 ; i < sm.size()-1 ; i++){
        if(sm[i] == '0'){
            ll target = (1 << (len-i)) - 1;
            mark[target] = 1;
        }
    }
    for(int i = 1; i <= n ; i++) cout << mark[i] << " ";
    // ll mnew = 0;
    // for(int i = 1 ; i <= n ; i++){
    //     if(mark[i] == 1){
    //         mnew ^= 2 * i;
    //     }
    //     else mnew ^= i;
    // }
    // if(mnew >= 2 * k){
    //     cout << "YES";
    // }
    // else cout << "NO";
    cout << endl;
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
