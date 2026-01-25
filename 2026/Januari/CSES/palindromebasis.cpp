#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> palindrome;
    ll MOD = 1e9+7;
    ll MAXN = 4e4+1;
    // 1 digit
    // palindrome.push_back(0);
    for(ll i = 1 ; i <= 9 ; i++){
        palindrome.push_back(i);
    }
    for(ll i = 11 ; i <= 100 ; i+= 11){
        palindrome.push_back(i);
    }
    for (ll a = 1; a <= 9; a++) {
        for (ll b = 0; b <= 9; b++) {
            ll x = 100*a + 10*b + a;
            palindrome.push_back(x);
        }
    }
    for (ll a = 1; a <= 9; a++) {
        for (ll b = 0; b <= 9; b++) {
            ll x = 1000*a + 100*b + 10*b + a;
            palindrome.push_back(x);
        }
    }
    
    for (ll a = 1; a <= 9; a++) {
        for (ll b = 0; b <= 9; b++) {
            for (ll c = 0; c <= 9; c++) {
                ll x = 10000*a + 1000*b + 100*c + 10*b + a;
                if (x <= MAXN) palindrome.push_back(x);
            }
        }
    }
    ll t; cin >> t;
    int lenPalindrom = palindrome.size();
    vector<ll> dp(MAXN+1,0);
    dp[0] = 1;
    for(ll p : palindrome){
        for(ll j = 0 ; j <= MAXN ; j++){
            if(j - p>=0){
                dp[j] = (dp[j] + dp[j-p]) % MOD;
            }
        }
    }
    while(t--){
        ll n ; cin >> n ; 
        cout << dp[n] << endl;
    }



    
    

    return 0;
}