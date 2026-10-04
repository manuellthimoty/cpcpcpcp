#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>;
#define vint vector<int>;
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

string rotatecyclic(string s, int d){
    string ans = s;
    int n = s.size();
    for(int i =0 ;i < n ; i++){
        ans[(i + d) % n] = s[i];
    }
    return ans;
}

int countblok(string s){
    int n = s.size();
    int res = 1;
    int curc = 1; 
    for(int i = 1 ;i < n ; i++){
        if(s[i] == s[i-1]) curc ++;
        else{
            res += 1;
            curc--;
        }
    }
    return res;
}

void solve(){
    int n ; cin >> n;
    int ans = 0;
    string s; s.resize(n); cin >> s;
    for(int i = 0 ; i <= n ; i++){
        string curstr = rotatecyclic(s,i);
        int cur = countblok(curstr);
        ans = max(ans,cur);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
