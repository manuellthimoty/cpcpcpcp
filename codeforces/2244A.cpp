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
    string s; s.resize(n); cin >> s;
    int len = 0;
    bool streak = false;
    int cur = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '#'){
            if(streak) cur++;
            else{
                cur = 1;
                streak = true;
            }
        }
        else{
            if(streak){
                streak = false;
                len = max(len,cur);
                cur = 0;
            }
            else continue;
        }
    }
    len = max(len,cur);
    cout << (len+1)/2 << endl;
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
