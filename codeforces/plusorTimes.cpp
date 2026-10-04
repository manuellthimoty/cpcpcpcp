#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll max4(ll a, ll b, ll c, ll d){
    ll first = max(a,b); ll second = max(c,d);
    return max(first,second);
}

ll min4(ll a, ll b , ll c , ll d){
    ll first = min(a,b); ll second = min(c,d);
    return min(first,second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t ; cin >> t;
    ll p ; cin >> p;
    vector<vector<ll>> dp(t+1,vector<ll>(2));
    dp[0][0] = p; // untuk min
    dp[0][1] = p; // untuk max
    for(ll i = 1 ; i <= t ; i++){
        char opsi1; ll val1;
        cin >> opsi1 >> val1;
        ll hasil11 = 0;
        ll hasil12 = 0;
        if(opsi1 == '+'){
            hasil11 = dp[i-1][0] + val1;
            hasil12 = dp[i-1][1] + val1;
        }
        if(opsi1 == 'x'){
            hasil11 = dp[i-1][0] * val1;
            hasil12 = dp[i-1][1] * val1;
        }
        char opsi2; ll val2;
        cin >> opsi2 >> val2;
        ll hasil21 = 0;
        ll hasil22 = 0;
        if(opsi2 == '+'){
            hasil21 = dp[i-1][0] + val2;
            hasil22 = dp[i-1][1] + val2;
        }
        if(opsi2 == 'x' ){
            hasil21 = dp[i-1][0] * val2;
            hasil22 = dp[i-1][1] * val2;
        }
        dp[i][0] = min4(hasil11,hasil12,hasil21,hasil22);
        dp[i][1] = max4(hasil11,hasil12,hasil21,hasil22);
        // cout << dp[i][0] << " " << dp[i][1] << " ";
    }
    cout  << max(dp[t][0],dp[t][1]) << endl;
    

    return 0;
}