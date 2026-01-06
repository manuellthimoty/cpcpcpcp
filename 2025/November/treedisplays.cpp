    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;

    const int MOD = 998244353;
    const int G = 3; // primitive root untuk MOD (bukan M)
    
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n ; cin >> n ;
        vector <ll> s(n);
        for(ll i = 0 ; i < n ; i++){
            cin >> s[i];
        }
        vector <ll> c(n);
        for(ll i = 0 ; i < n ; i++){
            cin >> c[i];
        }
        // Kita mau cari indeks i < j < k shg si < sj < sk dan ci + cj +ck minimum
        ll INF = 1e9;
        vector <ll> dp(n,1e9);
        vector<ll> sum2(n,1e9);
        sum2[0] = c[0];
        ll maximum = 0 ;
        for(ll i = 0 ; i < n ; i++){
            for(ll j = 0 ; j < i ; j++){
                if(s[j]<s[i]){
                    sum2[i] = min(sum2[i],c[i]+c[j]);
            }
        }
    }
    // for(ll i = 0 ; i < n ; i++){
    //     cout << sum2[i] << " ";
    // }
    // cout << endl;
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 1 ; j < i ; j++){
            if(s[j]<s[i]){
                dp[i] = min(dp[i],sum2[j]+c[i]);
            }
        }
    }
    // for(ll i = 0 ; i < n ; i++){
    //     cout << dp[i] << " ";
    // }
    ll ans = *min_element(dp.begin(),dp.end());
    if(ans == 1e9){ cout << -1 << endl; return 0;}
    cout << ans << endl;

}