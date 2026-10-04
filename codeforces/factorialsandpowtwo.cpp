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
vector<ll> fact(16,0);
ll ans = 20;
ll n;
ll countBinary(ll n){
    ll count = 0;
    while(n){
        n &= (n-1);
        count ++;
        n = n >> 1;
    }
    return count;
}

void run(int idx, vector<ll>& v, vector<ll> curr = {}){
    if(idx == v.size()){
        ll acc = 0;
        for(auto c : curr){
            acc += c;
        }
        if(n >= acc) ans = min(ans,(ll)countBinary(n-acc) + (ll)curr.size());
        if(curr.empty()) return;

        return;
    }
    curr.push_back(v[idx]);
    run(idx + 1, v, curr);
    curr.pop_back();
    run(idx + 1, v, curr);
}
void precompute(){
    fact[0] = 1;
    for(int i = 1; i <=15 ; i++){
        fact[i] = fact[i-1] * i;
    }
}

void solve(){
    cin >> n; ans = 20;
    run(3,fact);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }

    return 0;
}
