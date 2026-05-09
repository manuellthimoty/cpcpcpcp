#include <bits/stdc++.h>
#include <vector>
using namespace std;
// using int128 = __int128_t;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long N, D, S;
    cin >> N >> D >> S;
    cout << "Debug - D: " << D << " N: " << N << " S: " << S << endl;
    if(D>N){
        cout <<  "0 " << N - (N % S) << endl;
        return 0;
    }
    if(S==1){
        cout << "her1 " << min(2*D,N);
        return 0;
    }
    if(S>D){
        cout << "her2 " << S << endl;
        return 0;
    }
    long long n=N/S;
    long long d=D/S;
    long long s=1;
    long long minimum=min(2*d,n);
    long long ans=minimum*S;
    vector<long long> factor_of_min;
    for(long long i=1;i*i<=minimum;i++){
        if(minimum%i==0){
            factor_of_min.push_back(i);
            factor_of_min.push_back(minimum/i);
        }
    }
    if(factor_of_min.empty()){
        cout << "1 "<< ans << endl;
        return 0;
    }
    if(factor_of_min.size()==2){
        //prime
        cout << "2 " << ans - S << endl;
        return 0;
    }
    factor_of_min.erase(factor_of_min.end());
    long long lower_bound=(ans-D)/S; 
    long long max_factor=*max_element(factor_of_min.begin(),factor_of_min.end());
    if(max_factor>=lower_bound){
        cout << "3 " << ans << endl;
    }
    else{
        cout << "4 "<< ans-S << endl;
    }
}