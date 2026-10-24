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

    ll a,b; cin >> a >> b;
    vector<vector<vector<ll>>> dp(20,vector<vector<ll>>(2,vector<ll>(2)));
    vector<int> posa,posb;
    ll copya = a; ll copyb = b;
    while(copya > 0){
        ll curdig = copya%10;
        copya /= 10;
        posa.push_back(curdig);
    }
    while(copyb > 0){
        ll curdig = copyb % 10;
        copyb /= 10;
        posb.push_back(curdig);
    }
    reverse(posa.begin(),posa.end());
    reverse(posb.begin(),posb.end());
    
    return 0;
}
