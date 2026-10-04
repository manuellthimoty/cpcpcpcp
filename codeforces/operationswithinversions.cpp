#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ; cin >> n ;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> mark(n);
    
    for(int i = 0 ; i < n ; i++) mark[i] = 0;
    int count = 0;
    for(int i = 0 ; i < n ; i ++){
        for(int j = i + 1 ; j < n ; j++){
            if(a[j]<a[i] && mark[j]!=1){
                mark[j] = 1;
                count++;
            }
        }
    }
    cout << count << endl;
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