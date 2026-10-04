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

    int n,k; cin >> n >> k;
    vector<ll> a(n);
    bool oks = false;

    for(int i = 0; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) if(a[i] % 2 == 0) oks = true;
    sort(a.begin(),a.end());
    if(!oks){
        // cout << "A";
        a[0]++;
        k--;
    }
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    for(int i = 0 ; i< n ; i++) pq.push((ll)a[i]);
    while(k > 0){
        int f = pq.top();
        pq.pop();
        pq.push(f+2);
        k--;
    }
    while(!pq.empty()){
        int f = pq.top();
        cout << f << " ";
        pq.pop();
    }




    return 0;
}
