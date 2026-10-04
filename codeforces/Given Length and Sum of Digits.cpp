#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string digitsToString(const vector<ll>& v) {
    string s;
    for (ll d : v) {
        s.push_back(char('0' + d));
    }
    return s;
}
void solve() {
    ll m,s ; cin >> m >> s ;
    vector<ll> dpMax(m);
    vector<ll> dpMin(m);
    vector<ll> resultMax(m);
    vector<ll> resultMin(m);
    for(ll i = 0 ; i < m ; i++){
        dpMax[i] = 0; resultMax[i] =0; dpMin[i] = 0; resultMin[i] = 0;
    }
    resultMax[0] = 9; resultMin[0] = 1;
    dpMax[0] = s - resultMax[0]; dpMin[0] = s - resultMin[0];
    bool NoSolsMax = false;
    bool NoSolsMin = false;
    while(dpMax[0] < 0){
        if(resultMax[0] <= 0 ) {
            NoSolsMax = true;
            break;
        }
        resultMax[0] --;
        dpMax[0] ++;
    }
    if(s <= 0) NoSolsMin = true;
    for(ll i = 1 ; i < m ; i++ ){
        if(dpMax[i-1] <= 0) break; 
        resultMax[i] = 9;
        dpMax[i] = dpMax[i-1] - resultMax[i];
        while(dpMax[i] < 0){
            resultMax[i] --;
            dpMax[i] ++;
        }
    }
    ll ansMax = 0; ll ansMin = 0;
    if(NoSolsMax){
        cout << -1 << endl;
        return;
    }
    if(m == 1 && s>=0 && s<=9){
        cout << s << " " << s <<endl;
        return;
    }
    if(s <= 0 || s > 9 * m){
        cout << -1 << " " << -1 << endl;
        return;
    }
    for(ll i = 0 ; i < m ; i++){
        resultMin[i] = resultMax[m-i-1];
    }
    if(resultMin[0] == 0){
        resultMin[0] ++;
        ll cur = 1;
        while(resultMin[cur] == 0 && cur < m){
            cur++;
        }
        resultMin[cur]--;
    }
    for(ll i = 0 ; i < m ; i++){
        ansMax = ansMax * 10 + resultMax[i];
        ansMin = ansMin * 10 + resultMin[i];
    }
    string resMin = digitsToString(resultMin);
    string resMax = digitsToString(resultMax);
    cout << resMin << " " << resMax;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}