#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    bool oks = true;
    int n = s.length();
    for(int i = 0; i < n ; i++){
        if(s[i] != s[0]){
            oks = false;
            break;
        }
    }
    if(oks) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}