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
    int n ; cin >> n;
    vector<ll> p(n);
    for(int i = 0 ; i <n ; i++) cin >> p[i];

    // 1 2 2 7 9
    sort(p.begin(),p.end());
    if(p[0] != 1){
        cout << 1;
        return 0;
    }
    ll need = 2;
    for(int i = 1;i < n ; i++){
        ll cur = p[i];
        if(cur > need){ 
            cout << need;
            return 0;
        }
        need = need + cur;
    }
    cout << need;

    return 0;
}
