#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n ; cin >> n;
    vector<ll> ans;
    ans.push_back(1);
    ans.push_back(1);
    ll i = 2;
    while(ans.back() <= 1e18){
        ll nums = ans[i-1] + ans[i-2];
        ans.push_back(nums);
        i++;
    }
    ll indeks = 0;
    while(ans[indeks] <= n){
        indeks++;
    }
    ll len = indeks;
    cout << len << endl;
    for(ll i = 0 ; i < len ; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    

    return 0;
}