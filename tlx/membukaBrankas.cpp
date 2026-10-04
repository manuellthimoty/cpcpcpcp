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
    string s,t; s.resize(n);t.resize(n); cin >>s >> t;
    vector<int> first(n),second(n);
    for(int i = 0 ; i < n ; i++){
        first[i] = s[i] - '0';
        second[i] = t[i] - '0';
    }
    int diff = (second[0] - first[0] + 10) % 10;
    bool oks = true;
    for(int i = 1; i < n ; i++){
        int curdiff = (second[i] - first[i] + 10) % 10;
        if(curdiff != diff) oks = false;
    }
    if(oks) cout <<"YA";
    else cout <<"TIDAK";
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
