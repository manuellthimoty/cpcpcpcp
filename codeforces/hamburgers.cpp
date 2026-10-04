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
int baseB = 0;
int baseS = 0;
int baseC = 0;

ll nb,ns,nc;
ll pb,ps,pc;

bool can(ll k, ll punya){
    ll addB = baseB * k ;
    ll addS = baseS * k ;
    ll addC = baseC * k ;

    ll needB = max(0LL,addB - nb);
    ll needS = max(0LL,addS - ns);
    ll needC = max(0LL,addC - nc);

    if(pb * needB + ps * needS + pc * needC <= punya){
        return true;
    }
    else return false;
}

void solve(){
    string s; cin >> s;
    for(auto c : s){
        if(c == 'B') baseB++;
        if(c == 'S') baseS++;
        if(c == 'C') baseC++;
    }
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    ll r; cin >> r;

    ll low = 1;
    ll high = 1e13;
    ll ans = 0;

    while(low <= high){
        ll mid = low + (high-low)/2;
        if(can(mid,r)){
            low = mid+1;
            ans = max(ans,mid);
        }
        else{
            high = mid-1;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
