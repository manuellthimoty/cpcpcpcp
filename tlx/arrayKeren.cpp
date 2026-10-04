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

const int mxA = 1e7;
int spf[mxA + 1];

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    GK();
    init();
    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    
    map<int,int> freq;
    bool oks = false;
    for(int i = 1; i <= n ; i++){
        int cur = a[i];

        int curPrime = spf[cur];
        int final =1 ;
        while(cur > 1){
            int curPrime = spf[cur];
            int cnt = 0;
            while(cur % curPrime == 0){
                cnt++;
                cur /= curPrime;
            }
            cnt = cnt% 2;
            if(cnt == 1){
                final *= curPrime;
            }
        }
        freq[final]++;
        if(freq[final] > 1){
            oks = true;
        }
    }
    
    int ans = (oks ? freq.size() + 1 : -1);
    cout << ans << endl;
    return 0;
}
