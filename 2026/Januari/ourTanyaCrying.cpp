// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll maxPower(ll n, ll k){
//     ll ans = 0;
//     ll nCopy = n;
//     while(nCopy/k > 0){
//         nCopy = nCopy / k;
//         ans++;
//     }
//     return ans;
// }

// long long power(long long base, int exp) {
//     if (exp == 0) {
//         return 1;
//     }    
//     long long half_power = power(base, exp / 2);    
//     if (exp % 2 == 0) {
//         return half_power * half_power;
//     } 
//     else {
//         return base * half_power * half_power;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ll n,k,a,b; cin >> n >> k >> a >> b;
//     ll nCopy = n;
   
//     vector<ll> powersOfK;
//     ll p = 1;
//     while(p <= n) {
//         powersOfK.push_back(p);
//         if(p > n / k) break;  // Prevent overflow
//         p *= k;
//     }
//     ll maxPow = powersOfK.size()-1;
//     vector<ll> basisK(maxPow+1);

//     for(ll i = maxPow ; i >= 0 ; i--){
//         ll curPow = powersOfK[i];
//         ll coeff = nCopy / curPow;
//         basisK[i] = coeff;
//         nCopy -= coeff * curPow;
//     }
//     ll ans = 0;
//     nCopy =n;
//     for(ll i = 0 ; i <= maxPow-1 ; i++){
//         if(basisK[i] > 0){
//             ans += (basisK[i] * a) + b;
//             nCopy = nCopy - basisK[i];
//         }
//         else{
//             ll targetHasil = nCopy/(k);
//             ll metodeBagi = b;
//             ll metodeKurang = (nCopy - targetHasil) * a;
//             ans += min(metodeBagi,metodeKurang);
//             nCopy = targetHasil;
//         }
//     }
//     // cout << maxPow << endl;
//     ans+= (basisK[maxPow] - 1) * a;
//     // for(auto x : basisK) cout << x << " " << endl;
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,a,b; cin >> n >> k >> a >> b;
    ll ans = 0;
    int last = 0;
    if(k == 1){
        cout << (n - 1) * a << endl;
        return 0;
    }
    while(n > 1){
        if(n % k == 0){
            ans += min(b,(n - (n/k)) * a);
            n = n/k;
            last = 0;
        }
        else{
            ll sisa = n % k;
            ans += (sisa) * a;
            n = n - sisa;
            last = 1;
        }
    }
    if(n == 0){
        ans -= a;
    }
    cout << ans << endl;
    return 0;
}