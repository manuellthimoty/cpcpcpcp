// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// void solve(){
//     int n ; 
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0 ; i < n ; i++){
//         cin >> a[i];
//     }
//     const ll INF = 1e9;
//     vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(3,vector<ll>(3)));
//     if(a[0] == 0){

//         dp[0][2][0]=0;
//         dp[0][2][1]=0;
//         dp[0][2][2]=1;
//     }
//     if(a[0]==1){
//         dp[0][2][0]=1;
//         dp[0][2][1]=0;
//         dp[0][2][2]=1;
//     }
//     for(int i = 10){\
//         if(a[i]==0){
//             if(dp[i-1][1][1] == 2 ){
//                 dp[i][1][1] = 0;
//                 dp[i][2][2]=1;
//             }
//             else if(dp[i-1][2][2]==2){
//                 dp[i][2][2]=0;
//                 dp[i][1][1]=1;
//             }
//             else{
//                  dp[i][1][1] = dp[i-1][1][1]+1;
//                  dp[i][2][2] = dp[i-1][2][2]+1;
//             }
//             int res = min(dp[i-1][1][0],dp[i-1][2][0]);
//             dp[i][1][0] = res;
//             dp[i][2][0] = res;
//         }
//         else{
//             if(dp[i-1][1][1]==2){
//                 dp[i][1][1] = 0;
//                 dp[i][2][2] = 1;
//                 dp[i][1][0] = INF;
//                 dp[i][2][0] = 1 + dp[i-1][2][0];
//             }
//             else if(dp[i-1][2][2]==2){
//                 dp[i][1][1]=1;
//                 dp[i][2][2]=0;
//                 dp[i][2][0]=INF;
//                 dp[i][2][1] = dp[i-1][2][2];
//             }
//             else{
//                 dp[i][1][1] = dp[i-1][1][1]+1;
//                 dp[i][2][2] = dp[i-1][2][2] +1;

//                 dp[i][1][0] = min(dp[i-1][1][0],dp[i-1][2][0]);
//                 dp[i][2][0] = 1 + min(dp[i-1][1][0],dp[i-1][2][0]);
//             }
//         }
//     }
//     cout << min(dp[n-1][1][0],dp[n-1][2][0]) << endl;
// }
 
//     int main() {
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//         int t ; cin >> t;
//         while(t--){
//             solve();
//         }
//     }

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // dp[i][turn] = minimum skip to kill up to index i
    vector<vector<int>> dp(n + 1, vector<int>(2, INF));

    dp[0][1] = (a[0] == 1);  // turn teman di awal, bunuh boss 0
    dp[0][0] = INF;          // kamu tidak mungkin mulai

    if (n >= 2) {
        // teman bunuh dua boss pertama
        dp[1][1] = (a[0] == 1) + (a[1] == 1);
        // kamu tidak mungkin dimainkan duluan
    }

    for (int i = 0; i < n; i++) {
        for (int turn = 0; turn < 2; turn++) {
            if (dp[i][turn] == INF) continue;

            // next turn
            int nt = 1 - turn;

            // kill 1 boss
            if (i + 1 < n) {
                int cost = dp[i][turn];
                if (turn == 1) {           // teman
                    cost += a[i + 1];      // sulit → skip
                }
                dp[i + 1][nt] = min(dp[i + 1][nt], cost);
            }

            // kill 2 boss
            if (i + 2 < n) {
                int cost = dp[i][turn];
                if (turn == 1) {
                    cost += a[i + 1] + a[i + 2];
                }
                dp[i + 2][nt] = min(dp[i + 2][nt], cost);
            }
        }
    }

    // jawaban adalah dp[n-1] atau dp[n-2]
    int ans = min(dp[n - 1][0], dp[n - 1][1]);
    if (n > 1) ans = min(ans, dp[n - 2][0]), ans = min(ans, dp[n - 2][1]);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}

