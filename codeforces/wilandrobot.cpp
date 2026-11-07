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
    map<int,int> cnt;
    vector<int> a(n+1,0);
    priority_queue<int> pq;
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int x; cin >> x;
        a[i] = x;
        pq.push(x);
        cnt[x]++;
    }

    int move = 1;
    int idx = 1;
    while(move <= n){
        if(move % 2 == 1){
            // william
            while(cnt[pq.top()] == 0){
                pq.pop();
            }
            int f = pq.top();
            ans += f;
            cnt[f] --;
        }
        else{
            while(idx <= n && cnt[a[idx]] == 0){
                idx++;
            }
            if(idx <= n) cnt[a[idx]]--;
            idx++;
        }
        move++;
    }
    cout << ans;
    return 0;
}
