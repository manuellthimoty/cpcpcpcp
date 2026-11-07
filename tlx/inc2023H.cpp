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
    int n,m ; cin >> n >> m;
    multiset<int> st;
    priority_queue<pair<int,int>> pq;
    for(int i = 0 ; i < n ; i++){
        int w,v; cin >> w >> v;
        pq.push({v,w});
    }
    for(int i = 0; i < m ; i++){
        int x; cin >> x;
        st.insert(x);
    }
    ll ans = 0;
    while(!pq.empty() && !st.empty()){
        pair<int,int> fr = pq.top();
        pq.pop();
        auto it = st.lower_bound(fr.second);
        if(it != st.end()){
            ans += fr.first;
            st.erase(it);
        }
    }

    
    cout << ans << endl;
    return 0;
}
