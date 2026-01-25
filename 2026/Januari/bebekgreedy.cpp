#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,b ; cin >> n >> b;
    vector<ll> h(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());
    ll count = 0;
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++){
        // cout << h[i] << endl;
        if(sum >= b){
            break;
        }
        sum += h[i];
        count +=1;
    }
    cout << count << endl;

    return 0;
}