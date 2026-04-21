#include <bits/stdc++.h>
using namespace std;

long long n, t, m;

int main(){
    cin >> t;
    while (t--){
        cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            arr[i] = x % m; 
        }
        
        int max = 1;
        int cur = 1;
        for (int i = 1; i < n; i++){
            if (arr[i] == arr[i-1]){
                cur++;
            } else {
                if (cur > max) max = cur;
                cur = 1;
            }
        }
        if (cur > max) max = cur;
        
        if (max >= m) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}