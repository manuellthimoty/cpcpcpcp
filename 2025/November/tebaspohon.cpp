#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N,M; cin >> N >> M;
    vector<long long> a;
    for (long long i = 0; i < N; i++)
    {
        long long val;
        cin >> val;
        a.push_back(val);
    }
    long long up=*max_element(a.begin(),a.end());
    long long down=0;
    long long max=0;
    while(down<=up){
        long long batas = (down+up)/2;
        long long sum = 0;
        for(auto x : a){
            if(batas<=x){
                sum+=(x-batas);
            }
        }
        if(sum>=M){
            down=batas+1;
            if(down>max){
                max=down;
            }
        }
        else{
            up=batas-1;
        }
    }
    if(max==0){
        cout << -1 << endl;
    }
    else{
        cout << max-1 << endl;
    }
}