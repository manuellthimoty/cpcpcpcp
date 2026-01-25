#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q ; cin >> n >> q;
    unordered_map<string,string> noTelp;
    for(int i = 0 ; i < n ; i++){
        string s; cin >> s;
        string nums ; cin >> nums;
        noTelp[s] = nums;
    }
    for(int i = 0 ; i < q ; i++){
        string s; cin >> s;
        if(!noTelp[s].empty()){
            cout << noTelp[s];
        }
        else{
            cout << "NIHIL";
        }
        if(i!=q) cout << endl;
    }

    return 0;
}