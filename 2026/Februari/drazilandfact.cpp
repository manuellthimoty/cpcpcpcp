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
    vector<int> fact(10);
    fact[0] = 1;
    for(int i =1 ; i <= 9 ; i++) fact[i] = fact[i-1] * i;
    ll prod = 1;
    vector<int> ans;
    for(int i = 0 ; i <n ; i++){
        int curdigit = s[i] - '0';
        prod = prod * fact[curdigit];
        for(int i = 2 ; i < 10 ; i++){
            while(prod % fact[i] == 0){
                ans.push_back(i);
                prod = prod/fact[i];
            }
        }
    }
    string final;
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    for(auto x : ans) final += to_string(x);
    cout << final << endl;
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
