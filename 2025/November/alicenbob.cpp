// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     long long t;
//     cin >> t ;
//     vector<long long> res;
//     while(t--){
//         long long n,a;cin >> n >> a;
//         vector<long long>v;
//         for(long long i = 0 ; i < n ; i++){
//             long long val;
//             cin >> val;
//             v.push_back(val);
//         }
//         int same = 1;
//         for(auto x : v){Q
//             if(x != a){
//                 same=0;
//             }
//         }
//         if(same == 1){
//             res.push_back(1);
//             continue;
//         }
//         long long alice_idx=0;
//         while(alice_idx<v.size() && a>v[alice_idx] ){
//             alice_idx++;
//         }
//         if(alice_idx<(long double)(v.size())/2){
//             long long ans = a+1;
//             res.push_back(ans);
//             continue;
//         }
//         if(alice_idx>=(long double)(v.size())/2){
//             long long ans = a-1;
//             res.push_back(ans);
//             continue;
//         }
//     }
//     for(auto x : res){
//         cout << x << endl;
//     }
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, a;
        cin >> n >> a;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        int less = 0, equal = 0, greater = 0;
        for(int x : v) {
            if(x < a) less++;
            else if(x == a) equal++;
            else greater++;
        }
        
        
        if(equal == n) {
            cout << "1337\n";
            continue;
        }
        
        
        int best_b;
        
        if(greater >= less) {
            
            best_b = a + 1;
            for(int x : v) {
                if(x > a) {
                    best_b = max(best_b, 2 * a - x + 1);
                }
            }
        } else {
            best_b = a - 1;
            for(int x : v) {
                if(x < a) {
                    best_b = min(best_b, 2 * a - x - 1);
                }
            }
        }
    
        best_b = max(0, best_b);
        best_b = min(2000000000, best_b);
        
        cout << best_b << "\n";
    }
    
    return 0;
}