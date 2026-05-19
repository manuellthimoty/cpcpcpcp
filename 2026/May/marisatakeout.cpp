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
    int n; cin >> n;
    int cnt0,cnt1,cnt2;
    cnt0 = 0; cnt1 = 0; cnt2 = 0;
    for(int i = 0 ; i < n ; i++){
        int k ; cin >> k;
        if(k == 0) cnt0++;
        else if (k == 1) cnt1++;
        else cnt2++;
    }
    int bnyk12 = min(cnt1,cnt2);
    int ans = 0; ans += bnyk12;
    cnt1 -= bnyk12;
    cnt2 -= bnyk12;
    ans += cnt1/3;
    ans+= cnt2/3;
    ans += cnt0;
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
