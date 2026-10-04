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

int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    int a,b; cin >> a >> b;
    vector<int> d;
    int g = gcd(a,b);
    for(int i = 1; i * i <= g ; i++){
        if(g % i == 0){
            d.push_back(i);
            if(g/i != i){
                d.push_back(g/i);
            }
        }
    }
    sort(d.begin(),d.end());
    int n ; cin >> n;
    // [1,3,9]
    while(n--){
        int l,r; cin >> l >> r;
        int left = d.size()-1;
        int low = 0;
        int high = d.size() -1;
        bool found1 = false;
        bool found2 = false;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(d[mid] >= l){
                left = min(left,mid);
                high = mid-1;
                found1 = true;
            }
            else{
                low = mid+1;
            }
        }
        int right = 0;
        low = 0;
        high = d.size() -1;
        while(low <= high){
            int mid  = low + (high-low)/2;
            if(d[mid] <= r){
                found2 = true;
                right = max(right,mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        if(right >= left && found1 && found2){
            cout << d[right] << endl;
        }
        else cout << -1 << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
