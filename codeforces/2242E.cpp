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
    int n,q ; cin >> n >> q;
    string s; s.resize(n); cin >> s;
    vector<ll> pref1(n),pref2(n);
    int blok1 = 0;
    int blok2= 0;

    bool prev_beda1 = false;
    bool prev_beda2 = false;
    for(int i = 0 ; i<n ; i++){
        char expected1 = (i % 2 == 0) ? '0' : '1';
        char expected2 = (i % 2 == 0) ? '1' : '0';

        bool beda1 = (s[i] != expected1);
        bool beda2 = (s[i] != expected2);
        if(beda1 && !prev_beda1) blok1++;
        if(beda2 && !prev_beda2) blok2++;
        
        pref1[i] = blok1;
        pref2[i] = blok2;

        prev_beda1 = beda1;
        prev_beda2 = beda2;
    }

    while(q--){
        int l,r,k; cin >> l >> r >> k;
        l--;r--;
        int ans1 = pref1[r] - pref1[l];
        if((s[l]-'0') != (l %2)){
            ans1++;
        }
        int ans2 = pref2[r] - pref2[l];
        if((s[l]-'0') != (1-(l%2))) ans2++;
        if(min(ans1,ans2) <= k) cout << "YES" << endl;
        else cout <<"NO" << endl;
    }
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
