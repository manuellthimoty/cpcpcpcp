#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <int> prime(77777);
    prime[0] = 2;
    prime[1] = 3;
    int nums = 5;
    int len = 1;
    while(nums > 0){
        if(len == 77777) break;
        int count = 0;
        for(int i = 2 ; i*i<=nums ; i++){
            if(nums % i == 0){
                count++;
                break;
            }
        }
        if(count == 0){
            len++;
            prime[len] = nums;
        }
        nums+=2;
    }
    int t ; cin >> t;
    while(t--){
        int n ; cin >> n ;
        cout << prime[n-1] << endl;
    }

    return 0;
}