#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    string ans = "Of";
    s[0] = (char) tolower(s[0]);
    for(auto p : s){
        ans += p;
    }
    cout << ans << endl;

    return 0;
}