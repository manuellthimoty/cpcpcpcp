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

void solve(){
    ll n ; cin >> n;
    if(n == 1){
        NO
        return;
    }
    bitset<60> b (n);
    string s = b.to_string();
    int i = 0 ;
    bool found = false;
    while(i < s.size() && s[i] != '1'){
        bool oks = true;
        string cur = s.substr(i,s.size() -i);
        int left = 0; int right = cur.size() -1;
        while(left <= right){
            if(cur[left] != cur[right]){
                oks = false;
                break;
            }
            left++;
            right--;
        }
        if(oks){
            if(cur.size() % 2 == 1 && cur[cur.size()/2] == '1'){
                i++;
                continue;
            }
            found = true;
            YES
            return;
        }
        i++;
    }
    if(!found){
        bool oks1=true;
        string cur1 = s.substr(i,s.size() -i);
        int left = 0 ; int right = cur1.size() -1;
        while(left <= right){
            if(cur1[left] != cur1[right]){
                oks1 = false;
                break;
            }
            left++;
            right--;
        }
        if(oks1){
            if(cur1.size() % 2 == 1 && cur1[cur1.size()/2] == '1'){
                NO;
                return;
            }
            YES
            return;
        }
    }
    NO; 
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
