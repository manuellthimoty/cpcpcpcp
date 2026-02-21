#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d(int n){
    int ans = 0;
    while(n > 0){
        ans += n % 10;
        n = n/10;
    }
    return ans;
}

void solve(){
    int x ; cin >> x;
    int count = 0;
    for(int y = x ; y <= x + 1e5 ; y++){
        if((y - d(y)) == x) count ++;
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
