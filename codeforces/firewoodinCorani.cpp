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

    ll n,q; cin >> n >> q;
    set<pair<int,int>> st;
    st.insert({1,n});
    ll curr = (n * (n+1))/2;
    while(q--){
        ll p; cin >> p;
        auto it = st.upper_bound({p,INT_MAX});
        it--;
        ll f = it->first;
        ll s = it->second;
        // cout << "SEKARANG : " << f << " " << s << " ";
        if(p < f || p > s){
            cout << curr << endl;
            continue;
        }
        curr -= (s-p+1 )* (p-f+1);
        cout << curr << endl;
        st.erase(it);
        if(p-1 >= f) st.insert({f,p-1});
        if(p+1 <= s) st.insert({p+1,s});

    }

    return 0;
}
