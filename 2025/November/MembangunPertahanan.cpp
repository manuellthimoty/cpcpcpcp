#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N,Q;
    cin >> N >> Q ;
    while(Q--){
        long long X;
        cin >> X ; 
        //long long batas = (N+1)/2;
        //genap, genap
        long long count = 0;    
        if(X % (N+2) == 0){
            for(long long a = 1 ; 2*a <= N;a++){
                long long res = X/(N+2);
                long long b = res+a;
                if((2*b - 1)<= N && (2*b-1)>=a){
                    count++;
                }
            }
        }
        if(X % (N+1) == 0){
            for(long long a = 1 ; (2*a-1) <= N;a++){
                long long res = X/(N+2);
                long long b = (res + a -1);
                if(2*b <= N && 2*b>=(2*a-1)){
                    count++;
                }
            }
        }
        for(long long a = 1 ; 2*a<=N; a++){
            if((X+a) % (N+1) == 0){
                long long res = (X+a)/(N+1);
                long long b = res + a -1;
                if(2*(res+a-1)<=N && b>=a){
                    count++;
                }
            }
        }
        for(long long a = 1 ; (2*a-1) <= N ; a++){
            if((X+a*(N+1)) % (N+2) == 0){
                long long res = (X+a*(N+1))/(N+2);
                if((2*res-1)<=N && (2*res-1)>=(2*a-1)){
                    count++;
                }
            }
        }
        cout << count << endl;
}}