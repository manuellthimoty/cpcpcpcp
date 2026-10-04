#include <bits/stdc++.h>
using namespace std;

bool firstCond(string s){
    if(s.length() < 4){
        return false;
    }
    for(int i = 0 ; i < s.length()-3 ; i++){
        if(
            s[i] == '2' && s[i+1] == '0' && s[i+2]=='2' && s[i+3] == '6'
        ){
            return true;
        }
        
    }
    return false;
}

bool secondCond(string s){
    if(s.length() < 4){
        return true;
    }
    for(int i = 0 ; i < s.length()-3 ; i++){
        if(
            s[i] == '2' && s[i+1] == '0' && s[i+2]=='2' && s[i+3] == '5'
        ){
            return false;
        }
        
    }
    return true;
}
void solve() {
    int n ; cin >> n ;
    string s ;
    s.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    bool con1 = firstCond(s);
    bool con2 = secondCond(s);
    if(con1 || con2){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }
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