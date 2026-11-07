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


int main() {
    GK();
    ll n,d,s; cin >> n >> d >> s;
    ll choose = min(n/s,2LL * d/s);

    if(choose % 2LL == 0){
        cout << max(s,choose*s);
        return 0;
    }
    // fac m st choose*s - choose/m * s <= d
    bool ok = false;
    if(choose -1 <= d/s){
        ok = true;
    }
    else {for(ll m = 2; m * m <= choose ; m++){
        if(choose % m == 0){
            if(choose - (choose/m) <= (d/s)){
                ok = true;
                break;
            }
            ll co = choose/m;
            if(co != m){
                if(choose - (choose/co) <= (d/s)){
                    ok = true;
                    break;
                }
            }
        }
    }
}
    
    if(ok){
        cout << max(s,choose*s);
        return 0;
    }
    else cout << max(s,(choose -1LL)*s);

    return 0;
}
