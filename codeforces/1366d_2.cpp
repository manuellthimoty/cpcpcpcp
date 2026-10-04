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
const int mxA = 1e7;
int spf[mxA + 1];
// vector<vector<int>> primefact(mxA+1);

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    vector<int> ans1(n,-1);
    vector<int> ans2(n,-1);
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        int cnt = 0;
        int cols1 = 1;
        int cntPow1 = 0;
        int cols2 = 1;
        // cout << cur << endl;
        bool done = false;
        while(cur > 1){
            int curP = spf[cur];
            // cout << curP << endl;
            cnt ++;
            if(cnt == 1) cols1 = 1;
            if(cnt == 2) cols2 = a[i]/cols1;
            if(cnt == 2){
                int d1 = a[i]/cols1;
                int d2 = a[i]/cols2;
                ans1[i] = d1;
                ans2[i] = d2;
                break;
            }
            while(cur % curP == 0){
                cur /= curP;
                cols1 = cols1 * curP;
            }
        }
        if(cnt < 2){
            ans1[i] = -1;
            ans2[i] = -1;
        }
    }
    for(int i = 0 ; i < n ; i++) cout << ans1[i] << " ";
    cout << endl;
    for(int i = 0 ; i < n ; i++) cout << ans2[i] << " ";

    return 0;
}
