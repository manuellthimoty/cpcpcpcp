#include <bits/stdc++.h>
using namespace std;
int digitsum(int nums){
    int ans = 0;
    while(nums > 0){
        ans += nums % 10;
        nums = nums/10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int count,n,k;
    count = 0;
    cin >> n >> k;
    for(int i = 1; i <= n ; i++){
        if(digitsum(i) == k) count++;
    }
    cout << count << endl;

    

    return 0;
}