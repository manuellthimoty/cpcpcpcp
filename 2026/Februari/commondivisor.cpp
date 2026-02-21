// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n ; cin >> n;
//     vector<int> a(n);
//     for(int i = 0 ; i < n ; i++){
//         cin >> a[i];
//     }
//     map<int,int> count;
//     for(int i = 0 ; i < n ; i++){
//         for(int j = 1; j * j <= a[i] ; j++){
//             if( a[i] % j == 0){
//                 count[j] ++;
//                 if( (a[i] / j) != j){
//                     count[a[i]/j] ++;
//                 }
//             }
//         }
//     }
//     int ans = 0;
//     for(auto p : count){
//         if(p.first > 1 && p.second > 1) ans = max(ans,p.first);
//     }
//     cout << ans << endl;


//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAXA = 1000000;
    vector<int> freq(MAXA + 1, 0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    for(int g = MAXA; g >= 1; g--){
        int countMultiples = 0;
        for(int multiple = g; multiple <= MAXA; multiple += g){
            countMultiples += freq[multiple];
        }
        if(countMultiples >= 2){
            cout << g << endl;
            return 0;
        }
    }

    return 0;
}