#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)


int main() {
    GK();

    int n,m; cin >> n >> m;

    vector<string> s(n);
    for(int i = 0 ; i < n ; i++) cin >> s[i];

    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<int>> inDeg(n,vector<int>(m,0));

    for(int i = 0;  i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            int ni = i;
            int nj  =j;

            if(s[i][j] == 'U'){
                ni--;
            }
            else if(s[i][j] == 'D'){
                ni++;
            }
            else if(s[i][j] == 'L'){
                nj--;
            }
            else nj++;
            if(ni >= 0 && ni < n && nj >=0 && nj < m){
                inDeg[ni][nj]++;
            }
        }
    }

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < m ; j++){
    //         cout << inDeg[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    auto bfs = [&] (int curri, int currj){
        int ci = curri; int cj = currj;
        while(ci >= 0 && ci <n && cj >= 0 && cj < m && !visited[ci][cj]){
            visited[ci][cj] = true;
            int ni = ci;
            int nj = cj;
            if(s[ci][cj] == 'U'){
                ni--;
            }
            else if(s[ci][cj] == 'D'){
                ni++;
            }
            else if(s[ci][cj] == 'L'){
                nj--;
            }
            else nj++;
            ci = ni;
            cj = nj;
        }
    };

    int ans =0;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(inDeg[i][j] == 0){
                ans++;
                bfs(i,j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j]){
                ans++;
                bfs(i,j);
            }
        }
    }


    cout << ans << endl;



    return 0;
}
