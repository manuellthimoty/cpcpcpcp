#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n =s.length();
    if(s[0] == s[n-1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}