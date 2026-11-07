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
    int n,x; cin >> x >> n;
    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        pq.push(x);
    }
    int cnt = 0;
    ll cursum = 0;
    while(!pq.empty()){
        // if(pq.size() == 1) break;
        ll f = pq.top();
        // cout << f << endl;
        pq.pop();
        cnt++;
        cursum += f;
        if(cnt == 2){
            ans += cursum;
            pq.push(cursum);
            cnt = 0;
            cursum = 0;
        }        
    }
    cout << ans;
}
int main() {
    GK();

    solve();

    return 0;
}
