#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    b_i = a_i+1 - a_1
    b_1 = a_2 - a_1
    b2 = a3 -a2
    
    b_n-2 = a_n-1 - a_n-2
    b_n-1 = a_n - a_n-1
    total = a_n - a_1
    */
    int t;
    cin >> t;
    while(t--){
        long long n ; cin >> n;
        vector <long long> a(n);
        for(long long i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        if(a[0]!=-1 && a[n-1]!=-1){
            ll result = max(a[0]-a[n-1],a[n-1]-a[0]);
            for(ll i = 0 ; i < n ; i++){
                if(a[i]==-1) a[i] = 0;
            }
            cout << result <<endl;
            for(ll i = 0 ; i < n ; i++){
                cout << a[i] << " ";
            }
            cout << endl;
            continue;
        }
        if(a[0]==-1 && a[n-1]!=-1){
            a[0]=a[n-1];
        }
        else if(a[0]!=-1 && a[n-1]==-1){
            a[n-1] = a[0];
        }
        else{
            a[0]=0;
            a[n-1]=0;
        }
        for(ll i = 1 ; i < n-1 ; i++){
            if(a[i]==-1) a[i] = 0;
        }
        cout << 0 << endl;
        for(ll i = 0 ; i < n ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
   
}