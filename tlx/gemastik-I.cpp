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


const int mxA = 1e6+5;
int spf[mxA + 1];
vector<int> primes;

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            // primes.push_back(i);
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}


int main() {
    GK();
    init();
    int n ; cin >> n;
    vector<int> a;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        while(x > 1){
            int curPrime = spf[x];
            int cnt = 0;
            while(x % curPrime == 0){
                x /= curPrime;
                cnt++;
            }
            a.push_back(cnt);
        }
    }
    int sz = a.size();
    if(sz == 0){
        cout << "ASTIK" << endl;
        cout << 0 << endl;
    }
    if(sz == 1){
        cout << "GEMA" << endl;
        cout << 1 << endl;
    }
    vector<ll> pref(sz);
    pref[0] = a[0];
    for(int i = 1; i < sz ; i++) pref[i] = pref[i-1] ^ a[i];
    if(pref[sz-1] == 0){
        cout << "ASTIK" << endl;
        cout << 0 << endl;
        return 0;
    }
    vector<ll> suf(sz);
    suf[sz-1] = a[sz-1];
    for(int i = sz-2 ; i >=0 ; i--) suf[i] = suf[i+1] ^ a[i];
    ll ans = 0;
    if(suf[1] < a[0]) ans++;
    if(pref[sz-2] < a[sz-1]) ans++;

    for(int choose = 1 ; choose < sz-1 ; choose++){
        ll right = suf[choose+1];
        ll left = pref[choose-1];
        ll expected = right ^ left;
        if(expected < a[choose]){
            ans++;
        }
    }
    cout << "GEMA" << endl;
    cout << ans << endl;
    


    return 0;
}
