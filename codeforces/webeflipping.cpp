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
    vector<int> a(n);
    input(a,0,n);
    vector<int> md(n);
    for(int i = 0 ; i < n ; i++){
        if(a[i] < 0) md[i] = 0;
        else md[i] = 1;
    }
    int cur = 0;
    vector<int> ans;
    for(int i = n-1 ; i>=0 ;i--){
        if(cur % 2 != md[i]){
            cur++;
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << endl;
    for(auto a : ans){
        cout << a << " ";
    }
    cout << endl;
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
