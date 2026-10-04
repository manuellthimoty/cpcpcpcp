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

ll ceil_div2(long long x) {
    if(x >= 0) return (x+1)/2;
    else return x/2;
}

ll floor_div2(long long x) {
    if(x >=0) return x/2;
    else return (x-1)/2;
}
bool check(ll R, ll A, ll B, ll C, ll D){
    ll x1 = C-R;
    ll x2 = A+R;
    ll y1 = D-R;
    ll y2 = B+R;

    if (x1 > x2 || y1 > y2) return false;
    ll M = 1000000000000LL;

    ll min_P = -M;
    min_P = max(min_P, y1 - M);
    min_P = max(min_P, x1 - M);
    min_P = max(min_P, ceil_div2(x1 + y1));

    ll max_P = M;
    max_P = min(max_P, M + x2);
    max_P = min(max_P, M + y2);
    max_P = min(max_P, floor_div2(x2 + y2));
    return min_P <= max_P;
}

void solve(){
    int n ; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for(int i = 0 ; i < n ; i++){
        ll f,s ; cin >> f >> s;
        x[i] = f;
        y[i] = s;
    }
    ll A = x[0] + y[0];
    ll B = x[0] - y[0];
    ll C = A;
    ll D = B;

    for(int i = 1; i < n ; i++){
        A = min(A, x[i] + y[i]);
        B = min(B, x[i] - y[i]);
        C = max(C,x[i] + y[i]);
        D = max(D,x[i] - y[i]);
    }
    ll low = 0 ; 
    ll high = 4e12;
    ll ansR = -1;
    while(low <= high){
        ll mid = low + (high - low) /2;
        if(check(mid,A,B,C,D)){
            ansR = mid;
            high = mid- 1;
        }
        else{
            low = mid + 1;
        }
    }
    ll x1 = C - ansR;
    ll x2 = A + ansR;
    ll y1 = D - ansR;
    ll y2 = B + ansR;

    ll M = 1e12;
    ll ansP = max({-M, y1-M,x1-M, ceil_div2(x1+y1)});
    ll ansQ = max({-M,x1-ansP,ansP-y2});

    cout << ansR << endl;
    cout << ansP << " " << ansQ << endl;

    
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
