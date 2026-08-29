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
    int n ; cin >> n;
    int m = 2*n;
    vector<int> a(m);
    for(int i = 0 ; i < m ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<int> all_pos;
    for(int i = 0 ; i < m-1 ; i++){
        all_pos.push_back(a[i] + a[m-1]);
    }
    multiset<int> st;
    for(auto x : a) st.insert(x);
    for(auto check : all_pos){
        int x = check;
        int right = a[m-1];
        int left = check - right;
        multiset<int> cur = st;
        cur.erase(cur.find(right));
        cur.erase(cur.find(left));
        x = max(right,left);

        bool found = true;
        vector<pair<int,int>> logs;
        logs.push_back({left, right});


        while(!cur.empty()){
            auto it_right = prev(cur.end());
            int val_right = *it_right;

            cur.erase(it_right);

            int val_left = x - val_right;
            auto it_left = cur.find(val_left);

            if(it_left == cur.end()){
                found = false;
                break;
            }

            cur.erase(it_left);
            logs.push_back({val_left, val_right});
            x = val_right;
        }
        if(found){
            cout << "YES" << '\n';
            cout << check << '\n';
            for(auto p : logs){
                cout << p.first << " " << p.second << '\n';
            }
            return;
        }
    }
    cout << "NO" << '\n';
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
