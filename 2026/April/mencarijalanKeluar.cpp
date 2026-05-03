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
int n ;

bool check(float k, int turn){
    // misal dp[i][j] menyatakan apakah i bisa sampai di detik
    vector<vector<bool>> dp(n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < turn ; j++){
            if()
        }
    }

}

void solve(){
    int q,t; cin >> n >> q >> t;
    int Sx,Sy ; cin >> Sx >> Sy;
    int Dx,Dy; cin >> Dx >> Dy;
    vector<pair<int,int>> first(n);
    vector<pair<int,int>> next(n);
    for(int i = 0 ; i < n ; i++){
        int xfirst,yfirst,xsecond,ysecond;
        cin >> xfirst >> yfirst >> xsecond >> ysecond;
        first[i] = make_pair(xfirst,yfirst);
        next[i] = make_pair(xsecond,ysecond);
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
