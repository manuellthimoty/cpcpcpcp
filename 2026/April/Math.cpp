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

int n=1e6;
vector<bool> is_prime(n+1, true);
vector<int> primes;
void build_sieve() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (ll)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i <= n ; i++){
        if(is_prime[i]) primes.push_back(i);
    }
}


void solve(){
    int n ; cin >> n;
    if(n == 1){
        cout << 1 << " " << 0 << endl;
        return;
    }
    ll mx = 0;
    ll ans = 1;
    vector<ll> powers;
    for(auto p : primes){
        if(p > n) break;
        if(n % p == 0){
            ans = ans * p;
            ll cnt = 0;
            while(n % p == 0){
                n = n/p;
                cnt++;
            }
            mx = max(mx,cnt);
            powers.push_back(cnt);
        }
    }

    ll trgt = 1;
    ll mnCara = 0;
    while(trgt < mx){
        trgt *= 2;
        mnCara++;
    }

    bool kalilagi = false;
    for(ll p : powers){
        if(p < trgt){
            kalilagi = true;
            break;
        }
    }
    if(kalilagi) mnCara++;

    cout << ans << " " << mnCara << endl;

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    build_sieve();
    while (t--) {
        solve();
    }

    return 0;
}
