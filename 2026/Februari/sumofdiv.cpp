#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M = 1e9 + 7;
    int n ; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n ; i++){
        ans += (n/i) * i;
    }
    cout << ans << endl;

    return 0;
}