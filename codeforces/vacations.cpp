#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a;
    for(int i = 0 ; i < n ; i++){
        int val;
        cin >> val;
        a.push_back(val);
    }
    vector<vector<int>> dp(n, vector<int>(3, 1e5));
    dp[0][0]=1;
    if(a[0]==1 || a[0]==3){
        dp[0][1]=0;
    }
    else{
        dp[0][1]=1e5;
    }
    if(a[0]==2 || a[0]==3){
        dp[0][2]=0;
    }
    else{
        dp[0][2]=1e5;
    }
    for(int i = 1 ; i < n ; i++){
        dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        if(a[i]==1 || a[i]==3){
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }
        if(a[i]==2 || a[i]==3){
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout << min({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) <<endl;


}