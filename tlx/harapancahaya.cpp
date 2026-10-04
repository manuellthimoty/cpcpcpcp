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

    int n ; cin >> n;
    string s; s.resize(n); cin >> s;
    vector<int> sm(n/2 + 5,0);
    if(n == 1){
        cout << 0;
        return 0;
    }
    int i = 0 ;
    int j = n-1;
    while(i <= j){
        int selisih = s[j] - s[i];
        selisih += 26;
        selisih %= 26;
        sm[i] = selisih;
        // cout << sm[i] << " ";
        i++;
        j--;
    }
    // cout << endl;
    int lst = -1;
    int ans = 0;
    for(int i = 0 ; i < n/2 + 2 ; i++){
        if(sm[i] != 0) lst = i;
    }
    for(int i = 0 ; i <= lst; i++) cout << sm[i] << ' ';
    if(lst == -1){
        cout << 0 ;
        return 0;
    }
    for(int i = 0; i <= lst - 1 ; i++){

        if(sm[i] != sm[i+1]) ans++;
    }
    if(sm[lst] != 0) ans++;
    cout << ans;

    return 0;
}
