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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ;i < n ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    int ans = n;
    for(int tot = 1 ; tot <= n; tot ++){
        vector<set<int>> st(tot);
        bool ok = true;
        int i = 0;
        
        while(i < n){
            int cur = a[i];
            int choose = -1;
            int mn = n;
            for(int j = 0 ; j < tot ; j++){
                if(st[j].size() == 0){
                    choose = j;
                    break;
                }
                if(*st[j].rbegin() == cur) continue;
                if(st[j].size() < mn){
                    choose = j;
                    mn = st[j].size();
                }
            }
            if(choose != -1){
                st[choose].insert(cur);
                i++;
            }
            else{
                ok = false;
                break;
            }
        }
        for(int x = 0 ; x < tot ; x++){
            if(st[x].size() > k){
                ok = false;
                break;
            }
        }
        if(ok){
            ans = min(ans,tot);
        }
    }
    cout << ans << '\n';
    vector<set<int>> st_ans(ans);
    int i = 0;
    while(i < n){
        int cur = a[i];
        int choose = -1;
        int mn = n;
        for(int j = 0 ; j < ans ; j++){
            if(st_ans[j].size() == 0){
                choose = j;
                break;
            }
            if(*st_ans[j].rbegin() == cur) continue;
            if(st_ans[j].size() < mn){
                choose = j;
                mn = st_ans[j].size();
            }
        }
        if(choose != -1){
            st_ans[choose].insert(cur);
            i++;
        }
        else{
            break;
        }
    }
    for(int i = 0 ; i < ans ; i++){
        cout << st_ans[i].size() << " ";
        for(const auto& x : st_ans[i]){
            cout << x << " ";
        }
        cout << '\n';
    }
}
// 2 3 3 4 5 6 7
// 1 1 2 2 3 3
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
