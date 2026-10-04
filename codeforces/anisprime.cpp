#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n ;
    cin >> n ; 
    vector<ll> a(n);
    for(int i = 0 ; i < n ; i ++) a[i]=-1;
    for(int i = 1 ; i < n ; i+=2){
        a[i] = i+1;
    }
    //masukin ganjil
    for(int i = 2 ; i < n ;i+=2){
        if(a[i+1] % i == 0){
            a[i]=i;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i]==-1){
            a[i] == 
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    while(t--){
        solve();
    }
}