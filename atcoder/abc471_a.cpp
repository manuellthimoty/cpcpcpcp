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
    int a,b ; cin >> a >> b;
    bool cond1 = (a + b) == 9;
    bool cond2 = (a-b) == 9;
    bool cond3 = (a * b) == 9;
    bool cond4 = false;
    if(a % b == 0 && a/b == 9) cond4 = true;
    if(cond1 || cond2 || cond3 || cond4){
        cout << "Nine" << '\n';
    }
    else{
        cout << "Nein" << '\n';
    }

    

    return 0;
}
