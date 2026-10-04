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
// 2^ k = 2 ^{k-1} + 2 ^ {k-1}
// 9 = 1001
// 9 = 2 ^ 3 + 2 ^ 0 = 2 ^ 2 + 2 ^ 2 + 2 ^ 0 = 
ll power(ll a, ll b){
    if(b == 0) return 1;
    if(b % 2 == 0) return power(a,b/2) * power(a,b/2);
    else return a * power(a,b/2) * power(a,b/2);
}
void solve(){
    int n, k ; cin >> n >> k;
    bitset<30> biner(n);
    string s = biner.to_string();
    int cnt1 = 0;
    for(auto x : s){
        if(x == '1') cnt1++;
    }
    if(cnt1 > k || k > n ){
        NO;
        return;
    }
    YES;
    // cout << s << endl;
    //0010
    priority_queue<int> ans;
    vector<int> pos;
    for(int i = 0 ; i < 30 ; i++){
        if(s[i] == '1'){
            pos.push_back(29-i);
        }
    }
    // for(auto x  : pos) cout << x << " ";
    for(auto x : pos) ans.push(x);
    int cur = cnt1;
    if(cur!=k){
        int need = k - cur;
        while(need > 0){
            
            int val = ans.top();
            ans.pop();
            ans.push(val-1);
            ans.push(val-1);
            need--;
        }
    }
    while(!ans.empty()){
        cout << power(2,ans.top())  << " ";
        ans.pop();
    }
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
