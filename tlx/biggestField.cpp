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
    int n,q; cin >> n >> q;
    vector<int> a(n+1); 
    input(a,1,n+1);
    
    set<int> validsq;
    set<int> validrec;
    set<pair<int,int>> st;
    map<int,int> cnt;
    for(int i = 1; i <= n ; i++) cnt[a[i]]++;
    for(int i = 1; i <= n ; i++) st.insert({a[i],cnt[a[i]]});

    for(auto x:st){
        if(x.second >= 2){
            validrec.insert(x.first);
        }
        if(x.second >= 4){
            validsq.insert(x.first);
        }
    }

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int val ; cin >> val;
            // auto it = st.find({val,{}});
            cnt[val]++;
            if(cnt[val] >= 2){
                validrec.insert(val);
            }
            if(cnt[val] >= 4){
                validsq.insert(val);
            }
        }
        else if(op == 2){
            int val ; cin >> val;
            auto it = cnt.find(val);
            if(it == cnt.end() || it->second == 0) continue;
            cnt[val]--;
            if(cnt[val] < 2){
                auto itrec = validrec.find(val);
                if(itrec != validrec.end()){
                    validrec.erase(itrec);
                }
            }
            if(cnt[val] < 4){
                auto itsq = validsq.find(val);
                if(itsq != validsq.end()){
                    validsq.erase(itsq);
                }
            }
        }
        else{
            ll sq = -1;
            ll rec = -1;
            if(!validsq.empty()){
                ll side = *validsq.rbegin();
                sq = side * side;
            }
            if(validrec.size() >= 2){
                auto it = validrec.end();
                it--;
                ll x = (ll) *it;
                it--;
                ll y = (ll) * it;
                rec = x * y;
            }
            cout << sq << " " << rec <<endl;

        }

    }
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
