#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
    int n = 10000;
    vector<ll> d(n,0);
    for(int i = 1; i < n ; i++){
        int cnt = 1;
        for(int j = 2 ; j * j <= i ; j++){
            if(i % j == 0){
                cnt += j;
                if(i/j != j){
                    cnt += i/j;
                }
            }
        }
        d[i] = cnt;
    }
    ll sum = 0;
    for(int i = 1; i < n ; i++){
        for(int j = i+1; j < n ; j++){
            if(d[i] == j && d[j] == i){
                sum += i + j;
            }
        }
    }
    cout << sum;
}