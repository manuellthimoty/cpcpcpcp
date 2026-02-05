#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
void solve() {
    ll n,k ; cin >> n >>k;
    vector<ll> a(n);
    vector<ll> b(k);
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
        sum+= a[i];
    }
    for(ll i = 0 ; i < k; i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll i = n - 1;
    ll j = 0;
    ll curChoice = b[j];
    ll cheapest = 0;
    ll totalFree = 0;
    while(i >= 0){
        cheapest = a[i];
        curChoice --;
        if(curChoice == 0){
            totalFree += cheapest;
            j++;
            if(j < k){
                curChoice = b[j];
            }
            else{
                break;
            }

        }
        i--;
    }
    cout << sum - totalFree << endl;

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