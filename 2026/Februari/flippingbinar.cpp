#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>;
#define vint vector<int>;
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)


void solve(){
    int n ; cin >> n;
    string s ; s.resize(n); cin >> s;
    int cnt1 = 0;
    int cnt0 = 0;
    REP(i,0,n){
        if(s[i] == '1') cnt1++;
        else cnt0++;
    }
    if(cnt0 == n){
        cout << 0 << endl;
        return;
    }
    if(cnt1 % 2 == 0){
        cout << cnt1 << endl;
        REP(i,0,n){
            if(s[i] == '1') cout << i+1 << " ";
        }
        cout << endl;
        return;
    }
    if(cnt0 % 2 == 1){
        cout << cnt0 << endl;
        REP(i,0,n){
            if(s[i] == '0') cout << i+1 << " ";
        }
        cout << endl;
        return;
    }
    cout << - 1 << endl;
    
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
