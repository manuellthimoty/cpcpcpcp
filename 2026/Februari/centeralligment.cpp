#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;cin >> n;
    vector<string> s(n);
    int mx = 0;
    for(int i =0 ; i < n ; i++){
        string cur ; cin >> cur;
        s[i] = cur;
        mx = max(mx,(int) s[i].length());
    }
    for(int i = 0 ; i < n ; i++){
        int k = mx - s[i].length();
        k = k/2;
        for(int i = 0 ; i < k ; i++){
            cout << ".";
        }
        cout << s[i];
        for(int i = 0; i < k ; i++){
            cout << ".";
        }
        cout << endl;
    }



    return 0;
}