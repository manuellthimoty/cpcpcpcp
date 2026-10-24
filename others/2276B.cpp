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

void solve(){
    string s; cin >> s;
    int n = s.size();
    int curr = s[0] - '0';
    int ans = 1;
    bool oks1 = false;
    bool oks2 = false;
    for(int i = 1; i < n-1 ; i++){
        if(s[i-1] == s[i] && s[i] == s[i+1]) oks1 = true;
        if(s[i-1] != s[i] && s[i] != s[i+1]) oks2 = true;
    }
    if(oks1) ans++;
    if(oks2) ans++;
    cout << ans << endl;
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
