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

const int maxN = 2e5+5;
const int K = 20;
int st[K+1][maxN];
vector<int> arr;
int N;

void precompute(){
    copy(arr.begin(),arr.end(),st[0]);
    for(int i = 1; i<= K ; i++){
        for(int j = 0 ; j + (1 << i) <= N; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q ; cin >> N >> q;
    arr.resize(N);
    for(int i = 0 ; i < N ; i++) cin >> arr[i];
    precompute();
    while(q--){
        int l,r ; cin >> l >> r;
        l--;r--;    
        int len = r-l +1;
        int ans = 1e9;
        for(int i = K; i >=0 ; i--){
            if((1 << i) <= (r-l+1)){
                ans = min(ans, st[i][l]);
                l += (1 << i);
            }
        }
        cout << ans << endl;
    }
    
}
