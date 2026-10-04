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

// 1011        00010111

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    string s; s.resize(n); cin >> s;
    // pair<type,cnt>
    deque<pair<int,int>> dq;
    
    ll X = 0;
    int total0 = 0, total1 = 0;
    int current_zeros = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == 0){
            total0++;
            current_zeros++;
        } else {
            total1++;
            X += current_zeros;
        }
    }

    if (n > 0) {
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) {
                cnt++;
            } else {
                dq.push_back({a[i-1], cnt});
                cnt = 1;
            }
        }
        dq.push_back({a[n-1], cnt});
    }

    for(auto x : s){
        int type = x - '0';
        
        if(type == 1){
            if(total1 == 0) continue;
            int leading_zeros =0;
            if(!dq.empty() && dq.front().first == 0){
                leading_zeros = dq.front().second;
            }
            ll T = total0 - leading_zeros;
            X -= T;
            if(dq[0].first == 1){
                dq[0].second--;
                if(dq[0].second == 0){
                    dq.pop_front();
                }
            }
            else if(dq.size() > 1 && dq[1].first == 1){
                dq[1].second--;
                if(dq[1].second == 0){
                    dq.erase(dq.begin() +1);
                    if(dq.size() > 1 && dq[0].first == 0 && dq[1].first == 0){
                        dq[0].second += dq[1].second;
                        dq.erase(dq.begin() + 1);
                    }
                }
            }
            if(!dq.empty() && dq.back().first == 1){
                dq.back().second ++;
            }
            else {
                dq.push_back({1,1});
            }
        }
        if(type == 0){
            
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
