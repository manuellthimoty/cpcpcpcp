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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    vector<int> freq(m,0);
    for(auto x : a){
        freq[x % m] ++;
    }
    int ans = 0;
    if(freq[0] > 0) ans ++;
    for(int i =  1 ; i <= m/2; i++){
        int complement = m - i;
        if(i == complement && freq[i] > 0){
            ans ++;
            continue;
        }
        int cntleft = freq[i]; int cntright = freq[complement];
        if(cntleft == 0 && cntright == 0) continue;
        if(cntleft == 0) {ans += cntright; continue;}
        if(cntright == 0) {ans += cntleft;continue;}
        
        if(abs(cntleft - cntright) <= 1){
            ans ++;
        }
        else{
            if(cntleft > cntright){
                cntleft = cntleft - cntright - 1;
                ans ++;
                ans += cntleft;
            }
            else{
                cntright = cntright - cntleft -1;
                ans++;
                ans += cntright;
            }
        }
    }
    cout << ans << endl;
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
