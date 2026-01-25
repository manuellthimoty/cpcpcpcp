#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(),nums.end());
    int a = nums[0];
    int b = nums[1];
    int c = nums[2];
    int d = max(0,c - (a+b-1));
    cout << d << endl;
    

    return 0;
}