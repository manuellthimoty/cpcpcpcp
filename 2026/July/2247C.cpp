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
    int n ; cin >> n;
    bool oks = true;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n ; i++) cin >> a[i];
    for(int i = 0; i < n ; i++) cin >> b[i];
    for(int i = 0 ; i < n ; i++){
        if(a[i] != b[i]){
            oks = false;
            break;
        }
    }
    if(oks){
        cout << 0 << endl;
        return;
    }
    int cnt_diff_one = 0;
    int cnt_diff_zero = 0;

    int cnt_done_one = 0;
    int cnt_done_zero = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] != b[i]){
            if(a[i] == 1) cnt_diff_one++;
            else cnt_diff_zero++;
        }
        else{
            if(a[i] == 1) cnt_done_one++;
            else cnt_done_zero++;
        }
    }
    if(cnt_diff_one % 2 == 1){
        cout << 1 << endl;
        return;
    }
    else{
        if(cnt_diff_one >= 2){
            cout << 2 << endl;
            return;
        }
        else{
            if(cnt_done_one >=1 && cnt_done_zero >=1 ){
                cout << 2 << endl;
                return;
            }
            else cout << -1 << endl;
        }
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
