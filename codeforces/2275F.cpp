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
const int mxA = 1e6;


int spf[mxA + 1];
ll prime_hash[mxA + 1];

mt19937_64 rng(1337);

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    for (int i = 2; i <= mxA; i++) {
        if (spf[i] == i) {
            prime_hash[i] = rng();
        }
    }
}

ll tf(ll n) {
    ll ans = 0;
    while (n > 1) {
        ll curPrime = spf[n];
        ll cnt = 0;
        while (n % curPrime == 0) {
            n /= curPrime;
            cnt++;
        }
        cnt %= 2;
        if (cnt == 1) {
            ans ^= prime_hash[curPrime];
        }
    }
    return ans;
}

void solve() {
    ll n; 
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> a2(n);
    map<ll,ll> cnt2;

    for (int i = 0; i < n; i++) {
        a2[i] = tf(a[i]);
        cnt2[a2[i]]++;
    }

    ll ans = 0;
    ll currentPref = 0;

    for (int i = 0; i < n; i++) {
        currentPref ^= a2[i];
        ans += cnt2[currentPref];
    }

    cout << ans << endl;
}
int main() {
    GK();
    init();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
