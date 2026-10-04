#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> ans;

void solve(vector<int> cur, int cur_sum,int cur_len, int max_len){
    if(cur_len == max_len){
        if(cur_sum == 0) ans.push_back(cur);
        return;
    }
    vector<int> cur_plus = cur;
    vector<int> cur_min = cur;
    cur_plus.push_back(1);
    cur_min.push_back(-1);
    solve(cur_plus,cur_sum+1,cur_len+1,max_len);
    if(cur_sum > 0){
        solve(cur_min,cur_sum-1,cur_len+1,max_len);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n ; cin >> n;
    solve({},0,0,n);
    cout << ans.size() << endl;
    for(auto a : ans){
        string s = "";
        for(auto x : a){
            if(x == 1) s.push_back('(');
            else s.push_back(')');
        }
        // for(auto x : a) cout << x << " ";
        // cout << endl;
        cout << s << endl;
    }   
    
    return 0;
}
