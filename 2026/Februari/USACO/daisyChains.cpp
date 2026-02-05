#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ; cin >> n;
    vector<int> a(n+1,0);
    for(int i = 1 ; i<= n ; i++) cin >> a[i];
    int count = n;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i+1 ; j<= n ; j++){
            int sum = 0;
            for(int k = i ; k<= j ; k++){
                sum += a[k];
            }
            int avg = 0;
            if(sum % (j - i + 1) != 0) continue;
            avg = sum/(j-i+1);
            for(int k = i ; k<= j ; k++){
                if(a[k] == avg){
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}