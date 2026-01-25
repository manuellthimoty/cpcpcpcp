#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
ll power(ll a,ll b){
    if(b == 0) return 1;
    if(b == 1) return a;
    ll half = power(a,b/2);
    if(b % 2 == 0){
        return half * half;
    }
    else{
        return a * half * half;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q; cin >> q;
    while(q--){
        ll n ; cin >> n;
        ll val = 9;
        ll count = 1;
        while(n - val*count > 0){
            n = n - val*count;
            val = 10 * val ;
            count++;
            }
        ll ans = 0;
        ll cur = power(10,count-1)-1;
        if(n % count == 0){
            // ans = cur + (n/count);
            // ans = ans % 10;
            ll number = cur + (n/count);  // 99 + 35 = 134
            string s = to_string(number);
            ans = s[s.length()-1] - '0';  // Ambil digit terakhir
        }
        else{
            ll curAns = cur + n/count;
            string next = to_string(curAns+1);
            ll remainder = n % count;
            ans = next[remainder-1] - '0';
        }
        cout << ans << endl;

    }
    

    return 0;
}