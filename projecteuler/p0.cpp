#include "bits/stdc++.h"
using namespace std;

int main(){
    long long ans = 0;
    for(long long i = 1 ; i <= 228000 ; i++){
        if(i % 2 == 1) ans += i * i;
    }
    cout << ans << endl;
}