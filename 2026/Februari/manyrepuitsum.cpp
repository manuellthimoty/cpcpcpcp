#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    int mx = 0;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    // sort(a.begin(),a.end());
    // reverse(a.begin(),a.end());
    vector<long long> count(mx+1,0);
    for(auto x : a){
        count[x] ++;
    }
    vector<long long> ans(mx+3,0);
    ans[mx] = count[mx];
    // cout << ans[mx] << endl;
    for(int i = mx-1 ; i >= 1 ; i--){
        ans[i] = ans[i+1] + count[i];
    }
    cout << endl;

        for(int i = 1 ; i <= mx; i++){
        int choose = ans[i] % 10;
        int toleft = ans[i] / 10;
        ans[i] = choose;
        ans[i+1] += toleft;
    }
    cout << endl;
    string final;
    if(ans[mx+1] > 0) final += to_string(ans[mx+1]);
    for(int i = mx ; i >= 1 ; i--){
        final += to_string(ans[i]);
    }
    cout << final << endl;
    return 0;
}