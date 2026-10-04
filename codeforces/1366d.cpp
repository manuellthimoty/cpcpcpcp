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

    for (int i = 2; i <= mxA; i++) {
        int temp = i;
        while (temp > 1) {
            int p = spf[temp];
            // primefact[i].push_back(p);
            while (temp % p == 0) temp /= p;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    vector<int> ans1(n);
    vector<int> ans2(n);
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        int cnt = 0;
        vector<int> cols;
        bool done = false;
        while(cur > 1){
            int curP = spf[cur];
            cnt ++;
            cols.push_back(curP);
            if(cnt == 2){
                int d1 = a[i]/cols[0];
                int d2 = a[i]/cols[1];
                ans1[i] = d1;
                ans1[i] = d2;
                break;
            }
            while(cur % curP == 0){
                cur = curP;
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
