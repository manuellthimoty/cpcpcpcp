#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ; cin >> n ;
    if(n==2) {
        cout << 9 << endl;
        return;
    }
    int max1 = n*n + n*n-1 + n*(n-1);
    int max2 = n*n-1 + n*n + n*n-2 + n*n-1-n;
    int max3 = n*(n-1) + n*n + n*(n-1)-1+n*(n-2);
    int max4 = n*(n-1)-1 + n*n-1 + n*(n-2)-1 + n*(n-1)-2 + n*(n-1);
    cout << max(max(max1,max2),max(max3,max4)) <<endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}