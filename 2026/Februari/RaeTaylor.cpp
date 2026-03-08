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
    vint a(n);input(a,0,n);
    
    int curmin = a[0];
    // queue<int> q;
    // q.push(a[0]);
    // for(int i = 1 ; i < n ; i++){
    //     if(a[i] > curmin){
    //         if(!q.empty()) q.pop();
    //     }
    //     else{
    //         q.push(a[i]);
    //     }
    //     curmin = min(curmin,a[i]);
    // }
    // if(q.empty()) YES
    // else NO
    vint mx(n);
    mx[n-1] = a[n-1];
    for(int i = n-2 ; i>= 0 ; i--) mx[i] = max(mx[i+1],a[i]);
    bool ans = true;
    for(int i = 0 ; i < n-1 ; i++){
        if(curmin > mx[i+1]){
            NO
            return;
        }
        curmin = min(curmin,a[i]);
    }
    YES
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
