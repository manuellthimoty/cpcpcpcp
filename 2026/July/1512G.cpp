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

const int mxA = 1e7;

ll power(ll a, ll e) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a;
        a = a * a;
        e >>= 1;
    }
    return r;
}

int spf[mxA + 1];
int ans[mxA + 1];

void init() {
    memset(ans, -1, sizeof(ans));

    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    ans[1] = 1;
    for (int N = 2; N <= 1e7; N++) {
        int cur = N;
        ll current_d = 1;

        while (cur > 1) {
            int curPrime = spf[cur];
            int cnt = 1;

            while (cur % curPrime == 0) {
                cur /= curPrime;
                cnt++;
            }
            
            ll geom_sum = (power(curPrime, cnt) - 1) / (curPrime - 1);
            current_d *= geom_sum;
            
            if (current_d > 1e7) break; 
        }

        if (current_d <= 1e7 && ans[current_d] == -1) {
            ans[current_d] = N;
        }
    }
}
void solve(){
    int c; cin >> c;
    cout << ans[c] << '\n';
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    init();
    while (t--) {
        solve() ;
    }

    return 0;
}
