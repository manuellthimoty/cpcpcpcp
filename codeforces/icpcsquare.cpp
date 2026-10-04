#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long N){
    if(N==1) return false;
    if(N==2) return true;
    for(long long i=2;i*i<=N;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long N, D, S;
    cin >> N >> D >> S;
    if(D>N){
        cout << N - (N % S) << endl;
        return 0;
    }
    if(S>D){
        cout << S << endl;
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
        cout<< ans << endl;
        return 0;
    }
    if(isPrime(min(2*D,N)) && S==1){
        cout  << N-1 << endl;
        return 0;
    }
    if(S==1){
        long long final = min(2*D,N);
        bool oke1=false;
        if(final % 2 == 0) oke1=true;
        bool oke=false;
        if((N-D)==1){
            cout << N << endl;
            return 0;
        }
        for(long long i=2;i*i<=final;i++){
            if(final%i==0){
                if((final - (final/i))<=D){
                    oke=true;
                }
            }
        }
        if(oke || oke1){
            cout << final << endl;
        }
        else{
            cout << final-1 << endl;
        }
        return 0;
    }
 
    if(factor_of_min.size()==2){
        //prime;
        long long temp1=ans-S;
        long long temp2=N - (N%S);
        while(temp2-S>D){
            temp2-=S;
        }
        ans = S;
        long long x_max=1 + (D/S);
        while(S*x_max>N){
            x_max--;
        }
        long long final = max(temp1,max(S*x_max,temp2));
        cout << final << endl;
        return 0;
    }
    std::sort(factor_of_min.begin(),factor_of_min.end());
    factor_of_min.pop_back();
    long long lower_bound=(ans-D)/S;
    long long max_factor=*max_element(factor_of_min.begin(),factor_of_min.end());
    if(max_factor>=lower_bound){
        cout << ans << endl;
    }
    else{
        cout << ans-S << endl;
    }
}
