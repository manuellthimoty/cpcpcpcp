#include <bits/stdc++.h>
using namespace std;


long long countzero(long long n){
    int count=0;
    while(n%10==0){
        count++;
        n/=10;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;i<n;i++){
            cin >> dp[i][j];
        }
    }
    long long countzeros[n][n];
    long long res=1;
    countzeros[0][0]=countzero(dp[0][0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            countzeros[i][j]=
    }
}