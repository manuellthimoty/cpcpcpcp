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

void solve(){
    int n,k ; cin >> n >> k;
    int p = n/2;
    int q = n/2;
    if(n % 2== 1) p++;
    bool oks = false;
    if(k == 0){
        for(int i = 0 ; i < q ; i++){
            cout << 10;
            p--;
        }
        if(p == 1) cout << 1;
        cout << endl;
        return;
    }
    int first1 = 0;
    int first0 = 0;
    int remainder1 = 0;
    int remainder0 = 0;
    for(int i = 0 ; i <= k ; i++){
        int banyak1 = i;
        int banyak0 = k-i+2;
        int sisa1 = p- banyak1;
        int sisa0 = q - banyak0;
        if(sisa1 >= 0 && sisa0 >= 0 && abs(sisa1 - sisa0) <= 1){
            oks = true;
            first1 = banyak1;
            first0 = banyak0;
            remainder1 = 0;
            remainder0 = 0;
            // break;
        }
        if(oks){
            for(int i = 0 ; i < banyak1; i++) cout << 1;
            for(int i = 0 ; i < banyak0; i++) cout << 0;
            int cnt1 = 0;
            int cnt0 = 0;
            for(int i = 0 ; i < sisa1 ; i++){
                cout << 10;
                sisa0--;
            }
            if(sisa0 == 1) cout << 0;
            cout << endl;
            return;
        }
    }
    if(!oks){
        cout << -1 << endl;
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
