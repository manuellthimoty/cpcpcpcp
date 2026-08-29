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
    
    set<int> idx;
    multiset<pair<int,int>> st;
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        st.insert({a,i});
    }
    for(int i = 0 ;i < n ; i++) idx.insert(i);
    while(!st.empty()){
        // william
        pair<int,int> pr_wil =*st.rbegin();
        st.erase(pr_wil);
        int idx_wil = pr_wil.second;
        
        auto find_idx = idx.find(idx_wil);
        if(find_idx != idx.end()){
            idx.erase(find_idx);
        }

        // robot
        int idx_robot = *idx.begin();
        
    }
    return 0;
}
