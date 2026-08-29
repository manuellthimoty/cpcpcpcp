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
    string s; cin >> s;
    vector<int> even,odd;
    for(auto x : s){
        int num = x - '0';
        if(num % 2 == 0) even.push_back(num);
        else odd.push_back(num);
    }
    vector<int> res;
    reverse(even.begin(),even.end());
    reverse(odd.begin(),odd.end());
    while(!even.empty() && !odd.empty()){
        int front_even = even.back();
        int front_odd = odd.back();

        if(front_even < front_odd){
            even.pop_back();
            res.push_back(front_even);
        }
        else {
            odd.pop_back();
            res.push_back(front_odd);
        }
    }
    if(even.empty()){
        while(!odd.empty()){
            res.push_back(odd.back());
            odd.pop_back();
        }
    }
    if(odd.empty()){
        while(!even.empty()){
            res.push_back(even.back());
            even.pop_back();
        }
    }
    for(auto x : res){
        cout << x;
    }
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
