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
    string s; s.resize(n); cin >> s;
    vector<bool> is_printed(n,false);
    stack<int> st;
    for(int i = 0 ; i < n ; i++){
        char x = s[i];
        if(x == '1'){
            st.push(i);
        }
        else if(x == '2'){
            if(!st.empty()){
                int t = st.top();
                is_printed[t] = true;
                st.pop();
            }else is_printed[i] = true;
        }
        else is_printed[i] = true;
    }
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        if(!is_printed[i]){
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
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
