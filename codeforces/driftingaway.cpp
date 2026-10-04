#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> res;
    long long t ;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long n = s.size();
        if(n == 1) {
            res.push_back(1);
            continue;
        }
        long long countbintang = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='*') countbintang++;
        }
        if(countbintang>1){
            //pasti tak hingga
            res.push_back(-1);
            continue;
        }
        bool infinite = false;
        bool stateLeft = false;
        
        bool stateRight = false;
        long long countRight = 0;
        long long countLeft = 0;
        if(countbintang==1){
            if(s[0]=='*'){//jika bintang di awal
                for(long long i = 1 ; i <n;i++){
                    if(s[i]!='>') infinite = true;
                }
                if(!infinite){
                long long ans = n;
                res.push_back(n);
                continue;
            }        
            }
            if(s[n-1]=='*'){//jika bintang di akhir
                for(long long i = n-2;i>=0;i--){
                    if(s[i]!='<') infinite = true;
                }
                if(!infinite){
                long long ans = n;
                res.push_back(n);
                continue;
            }        
            }
            //di awal atau di akhir tapi ga infinite
        }

        for(long long i = 0 ; i< n ;i++){
            if(s[i]=='<'){
                countLeft++;
                stateLeft=true;
            }
            if(s[i]=='>'){
                countRight++;
                stateRight=true;
            }
            if(stateLeft && stateRight && s[i] == '<'){
                infinite=true;
                break;
            }
        }
        if(countbintang == 1){
            if(!infinite && stateLeft && stateRight){
                long long ans = 1 + max(countLeft,countRight);
                res.push_back(ans);
                continue;
            }
            else{
                infinite=true;
            }
        }
        if(infinite){
            res.push_back(-1);
            continue;
        }
        else{
            long long ans = max(countLeft,countRight);
            res.push_back(ans);
            continue;
        }
    }
    for(auto x : res) cout << x << endl;
}