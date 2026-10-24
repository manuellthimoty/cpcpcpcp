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


string convert(int n, int mxSz){
    string s;
    while(n > 0){
        if(n % 2 == 1){
            s += '1';
        }
        else s += '0';
        n = n/2;
    }
    while(s.size() < mxSz){
        s += '0';
    }
    return s;
}


int main() {
    int n ; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    ll mn = 1e18;
    ll mx = 0;

    string n1 = "";
    string n2 = "";
    for(int i = 0 ; i < n ; i++) n1 += '1';
    for(int i = 0 ; i < n ; i++) n2 += '0';

    for(int i = 0 ; i < (1 << n) ; i++){
        string curr = convert(i,n);
        if(curr == n1 || curr == n2) continue;        
        ll w = 0;
        ll h = 0;
        for(int j = 0 ; j < curr.size() ; j++){
            if(curr[j] == '0'){
                w += a[j];
            }
            else h += a[j];
        }
        mn = min(mn,w * h);
        mx = max(mx,w*h);
    }
    cout << mn << " " << mx;
    return 0;
}
