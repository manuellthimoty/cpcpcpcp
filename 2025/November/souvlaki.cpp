#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<int> result;
    while(T--){
        int n ; 
        cin >> n;
        vector<long long> nums;
        for(int i = 0 ; i < n ; i ++){
            long long val;
            cin >> val;
            nums.push_back(val);
        }
        bool equal = true;
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i]!=nums[i+1]){
                equal=false;
                break ;
            }
        }
        if(equal){
            int hasil = 1;
            result.push_back(hasil);
            continue;
        }
        bool oke = true;
        std::sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n - 1 ; i ++){
            if((nums[i+1]>nums[i]) && (i % 2 == 1)){
                oke=false;
                break;
            }
        }
        if(oke){
            int hasil = 1;
            result.push_back(hasil);
            continue;
        }
        else{
            int hasil = 0;
            result.push_back(hasil);
            continue;
        }
        