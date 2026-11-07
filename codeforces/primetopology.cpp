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

const int mxA = 1e7;
int spf[mxA + 1];
vector<int> primes;
vector<int> primes2; // p + 2 is prime and p prime
vector<int> primes4; // p +4 is prime and p prime  and p+2 prime
vector<ll> pr2;
vector<ll> pr;
vector<ll> pr4;
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
        if (spf[i] == i) primes.push_back(i);
    }

    for(auto p : primes){
        if(spf[p+2] == (p+2)){
            primes2.push_back(p+2);
        }
    }
    for(auto p : primes2){
        if(spf[p+2] == (p+2)){
            primes4.push_back(p+2);
        }
    }
    pr.resize(primes.size(),0);
    pr[0] = primes[0];
    for(int i = 1 ; i < pr.size() ; i++){
        pr[i] = pr[i-1] + primes[i];
    }
    pr2.resize(primes2.size(),0);
    pr2[0] = primes2[0];
    for(int i = 1 ; i < pr2.size() ; i++){
        pr2[i] = pr2[i-1] + primes2[i];
    }
    pr4.resize(primes4.size(),0);
    pr4[0] = primes4[0];
    for(int i = 1; i < pr4.size() ; i++){
        pr4[i] = pr4[i-1] + primes4[i];
    }
}

ll solve(int n, int k){
    ll MOD = 104206969;
    if(k > 4) return 0;
    if(k == 1) return n % MOD;
    if(k == 2){
        int low = 0;
        int high = primes.size()-1;
        int idx = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(primes[mid] <= n){
                low = mid+1;
                idx = max(idx,mid);
            }
            else high = mid-1;
        }
        if(idx == -1) return 0;
        ll ans = (1LL * n * (idx+1)) % MOD - (pr[idx] % MOD);

        return (ans + MOD) % MOD;
    }
    else if(k == 3){
        int low = 0;
        int high = primes2.size()-1;
        int idx = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(primes2[mid] <= n){
                low = mid+1;
                idx = max(idx,mid);
            }
            else high = mid-1;
        }
        if(idx == -1) return 0;
        ll ans = (2LL * n * (idx+1)) % MOD - (2LL * pr2[idx]) % MOD;
        return (ans+MOD) % MOD;
    }
    else if(k == 4){
        ll ans = max(0,n-7);
        return ans % MOD;
    }

}
void print10(vector<int>& arr){
    for(int i = 0 ;i < 10 ; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    GK();
    init();
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        cout << solve(n,k) << endl;
    }
    // print10(primes);
    // print10(primes2);
    // print10(primes4);
    // cout << primes4.size() << endl;

    

    return 0;
}
