#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ; cin >> n ;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int countnol = 0;
    int countsatu = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == 0) countnol++;
        else countsatu++;
    }
    if(countnol == 0){
        cout << "Alice" << endl;
    }
    else{
        if(a[0] == 1 || a[n-1] == 1){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
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