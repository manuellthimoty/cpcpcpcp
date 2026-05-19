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
    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++){
        cin >>a[i];
    }
    vector<int> pref(n+1),suff(n+1);
    pref[0] = 0;
    suff[0] = 0;
    pref[1] = a[1];
    for(int i = 2; i <= n ; i++) pref[i] = pref[i-1] + a[i];
    for(int i = n -1 ; i>=1 ; i--) suff[i] = suff[i+1] + a[i];

    int low = 1;
    int high = n;
    // int last_mid =0;
    while(low <= high && low >=1 && high <= n){
        if(abs(high - low) <= 1){
            break;
        }
        int mid = low + (high - low)/2;
        // bagi 2 klmpk : 
        // 1 2 3 ... mid -> pref[mid]
        // mid +1, mid+2 .. n -> suff[mid+1]
        printf("? %d", mid-low+1);

        for(int i = low; i <= mid ; i++){
            printf(" %d",i);
        }
        printf("\n");
        fflush(stdout);
        ll response;
        cin >> response;
        if((pref[mid] - pref[low-1]) != response){
            high = mid;
        }
        else{
            low = mid +1;
        }
        // last_mid = mid;
    }
    printf("? 1 %d\n",low);
    fflush(stdout);
    ll res; cin >> res;
    if(a[low] != res){
        printf("! %d\n",low);
        fflush(stdout);
        return;
    }
    else{
        printf("! %d\n",high);
        fflush(stdout);
        return;
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
