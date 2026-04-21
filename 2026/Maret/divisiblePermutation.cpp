#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n; cin >> n;
    vector<ll> p;
    
    ll left = 1, right = n;
    bool useLeft = false;
    
    while(left <= right){
        if(useLeft){
            p.push_back(left);
            left++;
        } else {
            p.push_back(right);
            right--;
        }
        useLeft = !useLeft;
    }
    reverse(p.begin(),p.end());
    
    for(ll i = 0; i < n; i++){
        cout << p[i];
        if(i < n-1) cout << " ";
    }
    // reverse(p.begin(),p.end());
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