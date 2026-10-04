#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b ; cin >> n >> m >> a >> b;
    int ans = 1e9;
    for(int x = 0 ; x <= 1000 ; x++){
        for(int y = 0  ; y <= 1000 ; y++){
            if(m * x + y >= n){
                ans = min(ans,x*b+y*a);
            }
        }
    }
    cout << ans << endl;

    return 0;
}