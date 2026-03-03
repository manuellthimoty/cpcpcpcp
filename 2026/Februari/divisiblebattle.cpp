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
bool isnds(vector<int> &arr){
    int n = arr.size();
    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}

int primefactor(int n){
    if(n ==1) return 1;
    int ans = 0;
    for(int i = 2 ; i * i <= n ; i++){
        if(n % i == 0){
            ans = i;
            while(n % i == 0){
                n = n/i;
            }
            if(n != 1) return -1;
            return ans;
            break;
        }
    }
    return n;
}
// tinjau bahwa Bob menang jika dan hanya jik aarray terurut dan semua 
// ai bebrentuk p^k, atau faktor prima tunggal, inio dapat dibuktikan, bahwa
// bob bisa memilih bentuk p p p p sebanyak k di akhir
// selain itu, alice menang
void solve(){
    int n ; cin >> n;
    vector<int> a(n);
    input(a,0,n);
    
    if(isnds(a)){
        cout << "Bob" << endl;;
        return;
    }
    int last_p = 1;
    bool bob_wins = true;
    
    for(int i = 0; i < n; i++){
        int p = primefactor(a[i]);
        if(p == -1 || p < last_p){
            bob_wins = false;
            break;
        }
        last_p = p;
    }
    
    if(bob_wins){
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
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
