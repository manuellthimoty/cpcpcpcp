#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll a,b; cin >> a >> b;
    ll countWhiteFirst = 0;
    // putih duluan
    ll temp_a = a;
    ll temp_b = b;
    ll multA = 1;
    ll multB = 2;
    ll countA = 0;
    ll countB = 0;
    while(temp_a - multA >= 0){
        temp_a -= multA;
        multA *= 4;
        countA++;
    }
    while(temp_b -multB >= 0){
        temp_b -= multB;
        multB *= 4;
        countB++;
    }
    if(countA > countB){
        countWhiteFirst = countB + countB + 1;
    }
    else{
        countWhiteFirst = countA + countA;
    }
    ll countBlackFirst = 0;
    // black duluan
    temp_a = a;
    temp_b = b;
    countA = 0;
    countB = 0;
    multA = 2;
    multB = 1;
    while(temp_b -multB >= 0){
        temp_b -= multB;
        multB *= 4;
        countB++;
    }
    while(temp_a -multA >= 0){
        temp_a -= multA;
        multA *= 4;
        countA++;
    }
    if(countB > countA){
        countBlackFirst = countA + countA + 1;
    }
    else{
        countBlackFirst = countB + countB;
    }
    cout << max(countBlackFirst,countWhiteFirst) << endl;
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