#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >>n;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    if(n <= 3) {
        cout << "NO SOLUTION " << endl;
        return 0;
    }
    for(ll i = 2 ; i<= n ; i+=2){
        cout << i << " ";
    }
    for(ll i = 1 ; i<=n ; i+=2){
        cout << i << " ";
    }
    
    

    return 0;
}