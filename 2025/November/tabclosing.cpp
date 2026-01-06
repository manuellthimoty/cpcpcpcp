#include <bits/stdc++.h>
using namespace std;
#include <string>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long a,b,n; cin >> a >> b >> n;
        if(a==b){
            cout << 1 << endl;
            continue;
        }
        if(a< 1LL*b*n){
            cout << 2 <<endl;
            continue;
        }
        cout << 1 <<endl;
    }
}

