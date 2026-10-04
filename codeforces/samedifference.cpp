#include <bits/stdc++.h>
using namespace std;
#include <string>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t;
    while(t--){
        int n ; 
        cin >> n;
        vector<char> s(n);
        for(int i = 0 ; i < n ; i++){
            cin >> s[i];
        }
        char patokan = s[n-1];
        int count = 0;
        bool same = false;
        int ans = 0;
        for(int i = n-2 ; i>=0 ; i--){
            if(s[i]==patokan){
                same=true;
                ans +=count;
                count = 0;
            }
            else{
                same=false;
                count++;
            }
        }
        if(!same) ans +=count;
        cout << ans << endl;
    }
}