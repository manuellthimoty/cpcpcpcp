#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> dp(51,0);
    dp[0]=1;
    dp[2] = 1;
    for(int i = 4 ; i <= 50 ; i+=2 ){
        for(int j = 0 ; j<= i-2 ; j+=2){
            dp[i] += dp[j] * dp[i-j-2];
        }
        // dp[i]/= 2;
    }
    ll n ; cin >> n;
    if(n == 0 || n == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << dp[n] << endl;
    

    return 0;
}