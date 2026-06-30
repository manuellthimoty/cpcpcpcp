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

int ans2(vector<int>& a, vector<int>& b, int n){
    int res = 0;
    vector<int> valid;
    vector<int> validIdx;

    for(int i =0 ; i < n ; i++){
        if(a[i] > b[i]){
            valid.push_back(a[i]);
            validIdx.push_back(i);
        }
    }
    int sz = valid.size();
    for(int i = 0 ;i < sz - 1 ; i++){
        for(int j = 0 ; j < sz - i - 1 ; j++){
            if(valid[j] > valid[j+1]){
                swap(valid[j],valid[j+1]);
                res++;
            }
        }
    }
    for(int i = 0 ; i < sz ; i++){
        if(valid[i] > b[validIdx[i]]){
            return 1e9+1;
        }
    }
    return res;
}

void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> b(n);
    for(int i = 0;i < n ; i++) cin >> b[i];
    vector<int> sorted = a;
    vector<vector<int>> available_at(n);
    
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        
        if (it == b.end()) {
            cout << -1 << endl;
            return;
        }
        
        int j = distance(b.begin(), it);
        available_at[j].push_back(i);
    }
    vector<int> p(n);
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int j = 0; j < n; j++) {
        for (int idx : available_at[j]) {
            pq.push(idx);
        }

        if (pq.empty()) {
            cout << -1 << endl;
            return;
        }

        p[j] = pq.top();
        pq.pop();
    }
    ll swaps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                swaps++;
            }
        }
    }

    cout << swaps << endl;
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
