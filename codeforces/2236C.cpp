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
    int a,b,x ; cin >> a >> b >> x;
    int cnt = 0;
    vector<int> hasilA;
    vector<int> hasilB;
    int curA = a;
    hasilA.push_back(a);
    int curB = b;
    hasilB.push_back(b);
    while(curA > 0){
        curA = curA/x;
        hasilA.push_back(curA);
    }
    while(curB > 0){
        curB = curB/x;
        hasilB.push_back(curB);
    }
    int ans = 1e9;
    int nA = hasilA.size();
    int nB = hasilB.size();
    for(int i = 0 ; i < nA ; i++){
        for(int j = 0 ; j < nB ; j++){
            ans = min(ans, i + j + abs(hasilA[i] - hasilB[j]));
        }
    }
    cout << ans << endl;
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
