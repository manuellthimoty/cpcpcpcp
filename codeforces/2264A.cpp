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
    vint a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vint sorted = a;
    sort(sorted.begin(),sorted.end());
    vint temp1;
    vint temp2;
    for(int i = 0 ; i < n ; i++){
        if(a[i] != sorted[i]){
            temp1.push_back(a[i]);
            temp2.push_back(sorted[i]);
        }   
    }
    reverse(temp1.begin(),temp1.end());
    bool oks = true;
    int sz = temp1.size();
    for(int i = 0 ; i < sz ; i++){
        if(temp1[i] != temp2[i]){
            oks = false;
            break;
        }
    }
    if(oks){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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
