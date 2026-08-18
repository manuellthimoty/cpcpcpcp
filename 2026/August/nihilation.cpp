#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b,a%b);
}
int main(){
    int n; cin >> n;
    int d = 0;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        d = gcd(d,x);
    }
    if(d > 1){
        cout << 1 << '\n';
        cout << d << ' ' << 1 << '\n';
    }
    else{
        cout << 2 << '\n';
        cout << 4 << ' ' << 2 << '\n';
        cout << 2 << ' ' << 1 << '\n';
    }
}
