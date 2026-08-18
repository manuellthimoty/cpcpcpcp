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
    int n ; cin >> n ;
    vector<int> a(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }

    
    vector<int> col(n);
    int d= 1;
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        int cnt = 0;
        while(cur % 2 == 0){
            cnt++;
            cur/=2;
        }
        if(i == 0){
            d = cur;
        }
        col[i] = cnt;
        d = gcd(d,cur);
    }

    priority_queue<int, vector<int>, greater<int>> mnh;
    for(auto x : col){
        mnh.push(x);
    }
    while(mnh.size() > 1){
        int a = mnh.top();
        mnh.pop();

        int b = mnh.top();
        mnh.pop();
        mnh.push(a +1);
    }
    
    ll pw = mnh.top();
    ll ans = (1LL << pw) * (ll)d;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
