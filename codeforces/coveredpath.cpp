#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1,v2 ; cin >> v1 >> v2;
    int t,d; cin >> t >> d;
    vector<int> a(t);
    a[0] = v1;
    a[t-1] = v2;
    for(int i = 1 ; i < t-1 ; i++){
        a[i] = a[i-1] + d;
    }
    for(int i = t-2 ; i >= 1 ; i--){
        if(abs(a[i] - a[i+1]) > d){
            a[i] = a[i+1] + d;
        }
    }
    int ans = 0;
    for(int i = 0; i < t ;i++) ans += a[i];
    cout << ans << endl;
    return 0;
}
