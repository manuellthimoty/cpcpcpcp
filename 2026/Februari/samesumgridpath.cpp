#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j  < n ; j++){
            char c ; cin >> c;
            if(c == '?'){
                a[i][j] = -1;
            }
            else{
                a[i][j] = c - '0';
            }
        }
    }
    bool oks = true;
    map<int,int> diag;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(a[i][j] != -1){
                if(!diag[i+j] || diag[i+j] == a[i][j] ){
                    diag[i+j] = a[i][j];
                }
                else{
                    oks = false;
                    break;
                }
            }
        }
    }
    if(!oks){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(a[i][j] == -1){
                if(diag[i+j]){
                    a[i][j] = diag[i+j];
                }
                else{
                    a[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}