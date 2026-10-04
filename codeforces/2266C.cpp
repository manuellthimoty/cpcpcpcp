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
    int n ; cin >> n;
    string s; s.resize(n); cin >> s;
    vector<int> cnt0(n,0),cnt1(n,0);
    if(s[0] == '0') cnt0[0] = 1;
    if(s[0] == '1') cnt1[0] = 1;
    int first1idx = -1;
    for(int i = 1 ; i < n ; i++){
        cnt0[i] = cnt0[i-1] + (s[i] == '0');
        cnt1[i] = cnt1[i-1] + (s[i] == '1');
        if(s[i] == '1'){
            if(first1idx == -1) first1idx = i;
        }
    }
    if(s[0] == '1'){
        cout << cnt0[n-1] << endl;
        return;
    }
    if(first1idx == -1){
        cout << 0 << endl;
        return;
    }
    int ans = min(cnt0[n-1],cnt1[n-1]);
    for(int i = first1idx-1; i < n-1 ; i++){
        int cntleftzeros = cnt1[i];
        int cntrightones = cnt0[n-1] - cnt0[i];
        int curr = cntleftzeros + cntrightones;
        ans = min(ans,curr);
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
