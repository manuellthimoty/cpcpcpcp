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
#define all(arr) arr.begin(),arr.end()
void solve(){
    int n ; cin >> n;
    vint a(n);
    input(a,0,n);
    int mins = a[0]; int maxs = a[0];

    bool issorted = true;
    for(int i = 0 ; i < n -1 ; i++){
        if(a[i] > a[i+1]){
            issorted = false;
            break;
        }
    }

    if(issorted){
        YES
        return;
    }
    int mxEven = -1;
    int mxOdd = -1;
    int mnEven = 1e9;
    int mnOdd = 1e9;


    for(int i = 0 ; i < n ; i++){
        mins = min(mins,a[i]);
        maxs = max(maxs,a[i]);
        if(a[i] % 2 == 1){
            mxOdd = max(mxOdd,a[i]);
            mnOdd = min(mnOdd,a[i]);
        }
        else if (a[i] % 2 == 0){
            mxEven = max(mxEven,a[i]);
            mnEven = min(mnEven,a[i]);
        }
    }

    if(mxEven == -1 && mnEven == 1e9){
        NO;
        return;
    }
    
    if(mxOdd == -1 && mnOdd == 1e9){
        NO;
        return;
    }

    if((mins + maxs) % 2 == 1){
        YES
        return;
    }
    if(mins % 2 == 0 && maxs % 2 == 0){
        // semua ganjil bisa ditukar
        vint bawah,tengah,atas;
        for(int i = 0 ; i < n ; i++){
            if(a[i] % 2 != 0) continue;
            if(a[i] >= mnOdd && a[i] <= mxOdd ){
                tengah.push_back(i);
            }
            else if(a[i] < mnOdd) bawah.push_back(i);
            else atas.push_back(i);
        }
        sort(all(bawah));
        sort(all(tengah));
        sort(all(atas));
        if(bawah.size() == 0 || atas.size() == 0){
            YES
            return;
        }
        if(bawah[bawah.size() -1] > atas[0]){
            NO
            return;
        }
        else{
            YES
            return;
        }
    }
    else{
        // semua genap bisa ditukar
        vint bawah,tengah,atas;
        for(int i = 0 ; i < n ; i++){
            if(a[i] % 2 != 1) continue;
            if(a[i] >= mnEven && a[i] <= mxEven ){
                tengah.push_back(i);
            }
            else if(a[i] < mnEven) bawah.push_back(i);
            else atas.push_back(i);
        }
        sort(all(bawah));
        sort(all(tengah));
        sort(all(atas));
        if(bawah.size() == 0 || atas.size() == 0){
            YES
            return;
        }
        if(bawah[bawah.size() -1] > atas[0]){
            NO
            return;
        }
        else{
            YES
            return;
        }
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
