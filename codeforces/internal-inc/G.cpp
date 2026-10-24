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

    int n; cin >> n;
    string s; cin >> s;
    int k = s.size();
    int r = 0;
    int t = 1;

    vector<vector<int>> a(n+1,vector<int>(n+1));

    
    


    for(auto x : s){
        if(x == 'L'){
            r--;
        }
        else if(x == 'R'){
            r++;
        }
        else{
            t *= -1;
            r += 3;
            r %= 6;
        }
    }

    return 0;
}
