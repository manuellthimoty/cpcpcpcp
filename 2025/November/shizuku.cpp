#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        if(n % 2 ==1){
            cout << 0 << endl;
            continue;
        }
        //n = 2a + 4b
        // 2a = n-4b
        int count = 0;
        for(int i = 0 ; i <= n/4 ; i++){
            if((n - 4*i) % 2 ==0) count++;
        }
        cout << count << endl;
    }
    
}