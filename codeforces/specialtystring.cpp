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
    stack<char> cur;
    for(int i = 0 ; i <n ; i++){
        if(cur.empty() || cur.top() != s[i]){
            cur.push(s[i]);
        }
        else{
            cur.pop();
        }
    }
    if(cur.empty()) YES
    else NO
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
