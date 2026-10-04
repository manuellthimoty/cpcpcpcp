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
    vector<ll> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    if (n <= 2) {
        for(auto x : a) cout << x << " ";
        cout << "\n";
        return;
    }

    vector<pair<int,int>> blocks;
    
    int cur_most_left = 0;
    int cur_most_right = 1;
    
    for(int i = 1 ; i < n-1 ; i++){
        ll left = a[i-1];
        ll right = a[i+1];
        if(abs(left) % 2 == abs(right) % 2){
            cur_most_right = i + 1;
        }
        else{
            blocks.push_back({cur_most_left, cur_most_right});
            cur_most_left = i;
            cur_most_right = i + 1;
        }
    }
    blocks.push_back({cur_most_left, cur_most_right});

    vector<ll> ans;
    ans.push_back(a[0]);
    
    for(auto b : blocks){
        vector<ll> diff;
        int fir = b.first;
        int sec = b.second;
        
        for(int i = fir + 1; i <= sec; i++){
            diff.push_back(a[i] - a[i-1]);
        }
        sort(diff.begin(),diff.end());
        
        for(auto x : diff){
            ans.push_back(ans.back() + x);
        }
    }
    
    for(auto x : ans){
        cout << x << ' ';
    }
    cout << '\n';
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
