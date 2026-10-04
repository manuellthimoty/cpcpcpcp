#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll powerMod(double a, ll b, ll m){
    if(b == 0) return 1;
    if(b == 1) return a % m ;
    ll half = powerMod(a,b/2,m);
    if(b % 2 == 0){
        return ((half % m) * (half % m)) % m;
    }
    else{
        return (((a % m) * (half % m) % m) * (half %m)) % m;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 0;

    return 0;
}