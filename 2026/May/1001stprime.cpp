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
const ll MAXprime = 6e6;
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

bool isPalindrome10(ll n){
    string s = to_string(n);
    ll i = 0;
    ll j  = s.size()-1;
    while( i <= j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

bool isPalindrome2(ll n){
    string s = bitset<20>(n).to_string();
    ll i = 0;
    while(s[i] == '0'){
        i++;
    }
    ll j = s.size() -1;
    while(i<=j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
ll modpow(ll a, ll e, ll mod) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}
ll chain(ll n){
    ll cnt = 0;
    while(n!=1){
        if(n % 2 == 0) n = n/2;
        else n = 3 *n +1;
        cnt++;
    }
    return cnt;
}

ll gcd(ll a, ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b,a % b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)) * b;
}
void solve(){
    ll ans = 1;
    ll mx = 1;
    for(ll i = 1; i < 1e6 ; i++){
        if(chain(i) > mx){
            mx = chain(i);
            ans = i;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    // cout << primes.size();
    // cout << primes[10000] << endl;
    // cout << primes[5];
    solve();
    // cin >> t;

    // while (t--) {
    //     solve();
    // }

    return 0;
}
