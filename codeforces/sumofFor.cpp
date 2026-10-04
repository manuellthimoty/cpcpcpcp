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

vector<vector<ll>> pairs(1e7+1);
void precompute(){
    for(ll i = 0 ; i*i <= 1e7/2 ; i++){
        for(ll j = 0 ; j*j <= 1e7/2 ; j++){
            ll cur =  i * i + j * j;
            if(cur > 1e7) continue;
            if(pairs[cur].empty()){
                pairs[cur].push_back(i);
                pairs[cur].push_back(j);
            }
        }
    }
}

void solve(){
    ll n ; cin >> n;
    vector<int> ans;
    for(ll first = 0 ; first <= n/2 ; first++){
        ll second = n - first;
        if(!pairs[first].empty() && !pairs[second].empty()){
            ans.push_back(pairs[first][0]);
            ans.push_back(pairs[first][1]);
            ans.push_back(pairs[second][0]);
            ans.push_back(pairs[second][1]);
            break;
        }
    }
    sort(ans.begin(),ans.end());
    for(auto a : ans) cout << a << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();   
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
