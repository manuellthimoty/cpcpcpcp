#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    auto last = unique(a.begin(),a.end());
    a.erase(last,a.end());
    int indeks = 0;
    int mex = 0;
    for(auto x : a){
        if(x != indeks){
            break;
        }
        indeks++;
    }
    cout << min(indeks,k-1) << endl;
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