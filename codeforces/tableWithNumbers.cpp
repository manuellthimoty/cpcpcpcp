#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ,h,l ; cin >> n >> h >> l;
    vector<int> a;
    for(int i = 0 ; i < n ; i ++){
        int nums ; cin >> nums;
        if(nums <= max(h,l)){
            a.push_back(nums);
        }
    }
    int minimum = min(h,l);
    int countDown =0;
    int countUp = 0;
    for(int x : a){
        if(x > minimum){
            countUp++;
        }
        else{
            countDown++;
        }
    }
    int ans = 0;
    if(countUp > countDown){
        ans = countDown;
    }
    else{
        ans = countUp + (countDown - countUp)/2;
    }
    cout << ans << endl;
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