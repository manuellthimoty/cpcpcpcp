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

set<int> pool;

string convert(int n, int mxSz){
    string s;
    while(n > 0){
        if(n % 2 == 1){
            s += '1';
        }
        else s += '0';
        n = n/2;
    }
    while(s.size() < mxSz){
        s += '0';
    }
    return s;
}

set<int> pool2;
void init(){
    vector<int> cand = {3,6,9,12,15};
    int n = cand.size();
    for(int i = 0 ; i < 32 ; i++){
        string cur = convert(i,5);
        int curXor = 0;
        for(int j = 0 ; j < cur.size() ; j++){
            if(cur[j] - '0' == 1){
                curXor ^= cand[j];
            }
        }
        pool.insert(curXor);
    }

    // for(int i = 0 ; i < 5 ; i ++){
    //     for(int j = 0 ; j < 5 ; j++){
    //         pool2.insert(cand[i] ^ cand[j]);
    //     }
    // }
}

void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n+5);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    vector<bool> isPool(16,false);
    for(auto x : pool){
        isPool[x] = true;
    }

    int cnt = 0;
    for(int i = 1; i <= n ; i++){
        if(isPool[a[i]]) cnt++;
    }
    cout << cnt << " ";

    while(q--){
        int p,x; cin >> p >> x;
        if(isPool[a[p]] && !isPool[x]) cnt--;
        if(!isPool[a[p]] && isPool[x]) cnt++;
        a[p] = x;
        cout << cnt << " ";
    }
    cout << endl;
}
int main() {
    GK();
    init();
    // for(auto x : pool) cout << x << " ";
    // cout << endl;
    // for(auto x : pool2) cout << x << " ";
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
