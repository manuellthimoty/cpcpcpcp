#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        long long x;
        cin >> x;
        long long mi= *min_element(a.begin(),a.end());
        long long ma= *max_element(a.begin(),a.end());
        if(mi<=x && x<=ma){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}