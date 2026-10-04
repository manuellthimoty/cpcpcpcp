#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n;
    ll l ; cin >> l;
    vector<ll> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    double ans =  0;
    for(int i = 1 ; i < n ; i++){
        ans = max(ans,(double)(a[i]-a[i-1]));
    }
    cout << fixed << setprecision(10) << max({ans/2,(double) a[0], (double) l - a[n-1]}) << endl;
    return 0;
}