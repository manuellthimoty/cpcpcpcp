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
const int mxA = 1e6;
int spf[mxA + 1];

vector<int> primesBelow(mxA+1,0);
void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    primesBelow[2] = 1;
    primesBelow[3] = 2;
    for(int i = 4; i <= mxA ; i++){
        if(spf[i] == i){
            primesBelow[i] = primesBelow[i-1] + 1;
        }
        else{
            primesBelow[i] = primesBelow[i-1];
        }
    }
}

bool is_squared(int n){
    return (int)(sqrt(n)) * (int)(sqrt(n)) == n;
}

void solve(){
    int n ; cin >> n;
    int ans = primesBelow[n] + 1 - primesBelow[(int)sqrt(n)];
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    init();
    while (t--) {
        solve();
    }

    return 0;
}
