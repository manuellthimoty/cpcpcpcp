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
    int n; cin >> n;
    char c; cin >> c;
    string s; s.resize(n); cin >> s;

    int i = 0 ;
    int j = n-1;
    int ans = 0;
    while(i <= j){
        if(s[i] == s[j]) {
            i++;
            j--;
            continue;        }
        if(s[i] == c || s[j] == c) ans ++;
        else ans += 2;
        i++;
        j--;
    }
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
