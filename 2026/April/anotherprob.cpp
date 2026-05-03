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
const ll MAXprime = 31625;
vector<ll> primes;
vector<bool> isprime(MAXprime);
// misal nilai akhir = X
// maka
// a/(a1 * a2 *.. * am) = X
// b/(b1 * b2 * .. * bn) = X
// misalkan banyakya faktor dri tinjau bahwa X haruslah merupakan faktor dari a dan B.
// maka X membagi gcd(a,b)


void sieve(){
    for(int i = 0 ; i < MAXprime ; i++) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for(int p = 2 ; p * p <= MAXprime ; p++){
        if(isprime[p]){
            for(int i = p * p ; i <MAXprime ; i+= p){
                isprime[i] = false;
            }
        }
    }
    for(int p = 2 ; p < MAXprime ; p++){
        if(isprime[p]) primes.push_back(p);
    }
}
ll gcd(ll a, ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b,a % b);
}

ll countPrimeFactors(ll n) {
    ll cnt = 0;
    for (ll i : primes) {
        if(1LL * i * i > n) break;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
    }
    if (n > 1) cnt++;
    return cnt;
}


void solve(){
    ll a,b,k; cin >> a >> b >> k;
    if(k == 1){
        bool oks = false;
        if(a!=b && (a % b == 0 || b % a == 0)) oks = true;
        if(oks) YES
        else NO
        return;
    }
    ll mx = countPrimeFactors(a) + countPrimeFactors(b);
    if(k <= mx) YES
    else NO
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    sieve();
    while (t--) {
        solve();
    }

    return 0;
}
