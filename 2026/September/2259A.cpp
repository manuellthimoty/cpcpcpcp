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
    int n,k; cin >> n >> k;
    string s; s.resize(n); cin >> s;
    int ans = 0;
    for(int i = 0 ; i < n- k+1; i += k){
        bool consecutive = true;
        for(int j = i ; j < i+k ; j++){
            if(s[j] != '1'){
                consecutive = false;
                break;
            }
        }
        if(consecutive) ans++;
    }
    cout << ans << endl;
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
