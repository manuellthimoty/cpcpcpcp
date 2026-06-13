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
    int k ; cin >> k;
    vector<int> a(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<int> freq(n+1,0);
    for(int i = 1 ; i <= n ; i++) freq[a[i]]++;
    vector<int> alls;
    for(int i = 1 ; i <= n ; i++){
        if(freq[i] > 0) alls.push_back(i);
    }
    sort(alls.rbegin(),alls.rend());
    int sz = alls.size();
    bool oks = false;
    // for(auto a : alls) cout << freq[a] << " ";
    if(sz == 1){
        if(freq[alls[0]] % 2 == 0){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        return;
    }
    for(int i = 0 ; i < sz-1 ; i++){
        if(freq[alls[i]] % 2 == 0){
            oks = true;
            break;
        }
        else{
            if(abs(alls[i] - alls[i+1]) <= k){
                oks = true;
                break;
            }
        }
    }
    if(freq[alls[sz-1]] % 2 == 0){
        oks = true;
    }
    if(oks) cout << "YES" << endl;
    else cout << "NO" << endl;
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
