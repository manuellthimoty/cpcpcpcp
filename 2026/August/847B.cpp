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
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    vector<vector<int>> seq;
    for(int i = 0 ; i < n ; i++){
        int k = a[i];
        if(seq.size() == 0){
            seq.push_back({});
            seq[0].push_back(k);
            continue;
        }
        bool found = false;
        int low = 0;
        int high = seq.size()-1;
        int pos = -1;
        while (low <= high){
            int mid = low + (high-low)/2;
            if(k > seq[mid].back() ){
                found = true;
                pos = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(found){
            seq[pos].push_back(k);
        }
        else{
            seq.push_back({});
            seq[seq.size() -1].push_back(k);
        }
    }
    for(auto s : seq){
        for(auto x : s){
            cout << x << ' ';
        }
        cout << '\n';
    }
}
int main() {
    GK();

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
