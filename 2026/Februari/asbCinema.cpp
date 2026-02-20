#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n ; cin >> n;
    vector<ll> a(n+1);
    vector<ll> f(n+1);
    for(int i = 1; i <= n ; i++) cin >> f[i];
    for(int i = 2 ; i <= n-1 ; i++){
        a[i] = (f[i+1] + f[i-1] - 2*f[i])/2;
    }
    int curSum = 0;
    for(int i = 2 ; i <= n-1 ; i++){
        curSum += a[i] * abs(i-1);
    }
    a[n] = (f[1] - curSum)/(n-1);
    curSum = 0;
    for(int i = 2 ; i<= n ; i++){
        curSum += a[i] * (n-i);
    }
    a[1] = (f[n] - curSum)/(n-1);
    for(int i = 1; i <= n ; i++) cout << a[i] << " ";
    cout << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
