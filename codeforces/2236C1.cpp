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
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)

void solve(){
    ll n ; cin >> n;
    vector<ll> a(n+1,0);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<ll> B(n,0);
    for(int i = 1; i <= n-1;i++) B[i] = i;
    vector<bool> dilarang(n,false);
    for(int i = 1; i <= n ; i++){
        ll low = i * a[i];
        ll high = i * a[i] + i-1;
        for(int j = low ; j <= high ; j++){
            if(j >= n) break;
            dilarang[j] = true;
        }
    }
    vector<int> ans;
    for(int i = 0; i < n ; i++){
        if(!dilarang[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
