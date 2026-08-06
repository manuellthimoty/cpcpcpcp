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
    ll n ; cin >> n;
    vector<ll> b(n);
    for(ll i = 0 ; i < n ; i++) cin >> b[i];
    vector<ll> sorted_b = b;
    sort(sorted_b.begin(),sorted_b.end());
    
    if(sorted_b[0] != 0){
        cout << -1 << "\n";
        return;
    }
    vector<ll> x, s, l;
    ll cur_len = 1;
    for(ll i = 0 ; i < n-1 ; i++){
        if(sorted_b[i] == sorted_b[i+1]){
            cur_len++;
        }
        else{
            s.push_back(sorted_b[i]);
            l.push_back(cur_len);
            cur_len=1;
        }
    }
    s.push_back(sorted_b[n-1]);
    l.push_back(cur_len);

    ll k = s.size();
    for(ll i = 0 ; i < k-1 ; i++){
        if((s[i+1] - s[i]) % l[i] != 0){
            cout << -1 << "\n";
            return;
        }
        ll target = (s[i+1] - s[i])/l[i];
        x.push_back(target);
    }
    bool oks = true;
    for(ll i = 0 ; i < (ll)x.size() - 1 ; i++){
        if(x[i] >= x[i+1]){
            oks = false;
            break;
        }
    }
    
    if(!oks){
        cout << -1 << "\n";
        return;
    }
    
    if(x.empty()){
        x.push_back(1);
    } else {
        x.push_back(x.back() + 1);
    }
    
    map<ll,ll> ans;
    for(ll i = 0 ; i < (ll)x.size() ; i++){
        ans[s[i]] = x[i];
    }
    
    for(ll i = 0 ; i < n ; i++){
        cout << ans[b[i]] << " ";
    }
    cout << "\n";
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
