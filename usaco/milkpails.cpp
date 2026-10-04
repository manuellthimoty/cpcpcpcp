#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pails.in", "r", stdin);
	

    int x,y,m ; cin >> x >> y >> m;
    int ans = 0;
    for(int i = 0; i <= 1000 ; i++){
        for(int j = 0 ; j <= 1000 ; j++){
            if(x * i + y * j <= m){
                ans = max(ans, x*i + y*j);
            }
        }
    }
    freopen("pails.out", "w", stdout);
    cout << ans << endl;

    return 0;
}