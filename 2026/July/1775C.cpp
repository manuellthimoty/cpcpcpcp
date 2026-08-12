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
    ll n,x; cin >> n >> x;
    string biner = bitset<60> (n).to_string();
    vector<int> b;
    if(n % 2 != 0) {
        b.push_back(0);
    }
    
    for(int i = 59 ; i >= 1 ; i--){
        if(biner[i] == '0' && biner[i-1] == '1'){
            b.push_back(60-i);
        }
    }
    
    b.push_back(60);
    
    ll last = n;
    map<ll,ll> ans;
    for(int i = 0 ; i < (int) b.size() ; i++){
        ll score = (n >> b[i]) << b[i];
        ll first = last; 
        if(ans.find(score) == ans.end()) {
            ans[score] = first;
        }
        ll second = ((n >> b[i]) + 1) << b[i];
        last = second;
    }
    auto it = ans.find(x);
    if(it == ans.end()){
        cout << -1 << '\n';
    }
    else cout << ans[x] << '\n';
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
