#include <bits/stdc++.h>
using namespace std;
#include <cmath>
void solve() {
    double x1,y1,x2,y2,r1,r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    if(x1 == x2 && y1 == y2){
        if(r1 == r2){
            cout << "bersentuhan" << endl;
        }
        else{
            cout << "tidak bersentuhan " << endl;
        }
        return;
    }
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2-y1));
    if(d + min(r1,r2) < max(r1,r2)){
        cout << "tidak bersentuhan " << endl;
        return;
    }
    if((r1 + r2) >= d){
        cout << "bersentuhan" << endl;
    }
    else cout << "tidak bersentuhan " << endl;
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
