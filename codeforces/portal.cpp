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
    int n,x,y ; cin >> n >> x >> y;
    vector<int> p(n+1);

    input(p,1,n+1); 
    
    vector<int> left;
    for(int i = 1 ; i <= x ; i++){
        left.push_back(p[i]);
    }
    vector<int> mid;
    for(int i = x + 1; i <= y ; i++){
        mid.push_back(p[i]);
    }
    vector<int> right;
    for(int i = y + 1 ; i<= n ; i++){
        right.push_back(p[i]);
    }
    int mnmid = 2e5+1;
    for(auto x : mid){
        mnmid = min(mnmid,x);
    }
    int sizemid = mid.size();
    int mididx = 0;
    for(int i = 0 ; i < sizemid ; i++){
        if(mid[i] == mnmid){
            mididx = i;
            break;
        }
    }
    vector<int> resmid;
    for(int i = 0; i < mid.size(); ++i)
        resmid.push_back(mid[(mididx + i) % mid.size()]);
        
    vector<int> conc;
    for(auto x : left) conc.push_back(x);
    for(auto x : right) conc.push_back(x);
    int sizeconc = conc.size();
    int start = sizeconc; 
    for(int i = 0 ; i < sizeconc ; i++){
        if(conc[i] > resmid[0]){
            start = i;
            break;
        }
    }
    for(int i = 0 ; i < sizeconc ; i++){
        if(i == start){
            for(auto x : resmid){
                cout << x << " ";
            }
        }
        cout << conc[i] << " ";
    }
    if(start == sizeconc){
        for(auto x : resmid){
            cout << x << " ";
        }
    }
    cout << endl;
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