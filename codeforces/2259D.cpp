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

void solve(){
    int n ; cin >> n;
    int cnt0 = 0;
    vector<int> a(n);
    for(int i = 0; i < n ; i++){
        int x; cin >> x;
        a[i] = x;
        if(x == 0) cnt0++;
    }
    if(cnt0 == 0){
        cout << "YES" << endl;
        for(int i = 0 ; i < n ; i++){
            cout << "A";
        }
    }
    else if(cnt0 == 1){
        cout << "NO";
    }
    else{
        int cntnow = 0;
        string ans; ans.resize(n);
        for(int i = 0 ; i < n ; i++){
            if(a[i] == 0){
                if(cntnow == 0){
                    ans[i] = 'A';
                    cntnow++;
                }
                else{
                    ans[i] = 'B';
                }
            }
            else ans[i] = 'C';
        }
        cout << "YES" << endl;
        cout << ans;
    }
    cout << endl;
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
