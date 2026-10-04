#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("diamond.in", "r", stdin);

    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int count = 0;
        for(int j = 0 ; j < n; j++){

            if(a[i] <= a[j] && a[j] <= a[i] + k){
                count++;
            }
        }
        ans = max(ans,count);
    }
    freopen("diamond.out", "w", stdout);
    cout << ans << endl;

    return 0;
}