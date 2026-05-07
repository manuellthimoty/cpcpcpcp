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

bool ispalindrome(int n){
    string s = to_string(n);
    int i = 0; int j = s.size()-1;
    while(i <= j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

void solve(){
    for(int x = 1 ; x <= 1e6 ; x++){
        string s1 = to_string(x);
        string s2 = to_string(2 * x);
        string s3 = to_string(3 * x);
        string s4 = to_string(4 * x);
        string s5 = to_string(5 * x);
        string s6 = to_string(6 * x);
        
        if (s1.size() != s6.size()) {
            continue;
        }
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        sort(s3.begin(), s3.end());
        sort(s4.begin(), s4.end());
        sort(s5.begin(), s5.end());
        sort(s6.begin(), s6.end());

        if (s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5 && s5 == s6) {
            cout << x << endl;
            return;
        }
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
