#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<int> ans(n+1);
    for(int i = n ; i >=1 ; i--){
        if(a[i] == i) ans[i] = i;
        else ans[i] = ans[a[i]];
    }
    for(int i =1 ; i <= n ; i++) cout << ans[i] << " ";
    

    return 0;
}