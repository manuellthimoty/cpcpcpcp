#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

void solve() {
    string s ; cin >>s;
    stack<char> ans;
    for(char c : s){
        if(!ans.empty() && c == ans.top()){
            ans.pop();
        }
        else{
            ans.push(c);
        }
    }
    if(ans.size() == 0) YES;
    else NO;

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