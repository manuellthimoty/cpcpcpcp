#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t;
    while(t--){
        int n ;
        cin >> n ;
        vector<long long> a(n);
        vector<long long> c(n);
        for(long long i = 0 ; i < n ; i ++){
            cin >> a[i];
        }
        for(long long  i = 0 ; i < n ; i++){
            cin >> c[i];
        }
        long long total = 0 ;
        for(auto x : c) total += x;
        long long maximum = 0;
        vector<long long> dp(n);
        for(long long i = 0 ; i < n ; i++){
            dp[i]=c[i];
            for(long long j = 0 ; j < i ; j++){
                if(a[j]<=a[i]){
                    dp[i]=max(dp[i],dp[j]+c[i]);
                }
            }
            maximum = max(dp[i],maximum);
        }
        cout << total - maximum << endl;
    }
}