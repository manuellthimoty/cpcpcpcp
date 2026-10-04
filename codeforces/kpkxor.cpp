#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
    long long n;cin >> n;
    vector <long long> a;
    for(long long i = 0 ; i< n ; i++){
        long long v ;
        cin >>v;
        a.push_back(v);
    }
    sort(a.begin(),a.end());
    long long len = a.size();
    long long sum = (len*(len-1))/2;
    long long same = 1;
    for(long long i = 0 ; i < n-1 ; i++){
        if(a[i]=a[i+1]){
            same++;
        }
        else{
            sum -= (same*(same-1))/2;
            same = 1;
        }
    }
    cout << sum;
}