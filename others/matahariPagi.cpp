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
    int n ; cin >> n;
    vector<int>a(n),b(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> d(n);
    for(int i = 0 ; i < n ; i++) d[i] = b[i] - a[i];
    if(d[n-1] < 0){
        cout << "TIDAK" << endl;
        return 0;
    }
    int days = d[n-1];
    bool ok = true;
    for(int i = 0 ; i < n ; i++){
        if(!(d[i] >= 0 && d[i] <= days)){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "YA" << endl;
    }
    else cout << "TIDAK" << endl;
}
