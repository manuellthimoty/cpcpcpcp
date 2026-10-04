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
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    ll sum = 0;
    for(auto x : a) sum += x;
    if(sum % n != 0){
        cout << "TIDAK SESUAI" << endl;
        return 0;
    }
    int l = -1; int r = -1;
    int cnt = 0;
    for(auto x : a){
        if(x != sum/n){

            cnt++;
        }
    }
    if(cnt > 2){
        cout << "TIDAK SESUAI" << endl;
        return 0;
    }

    if(cnt == 0){
        cout << "SESUAI" << endl;
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        if(a[i] != sum/n){
            if(l == -1){
                l = i;
            }
            else{
                if(r == -1){
                    r = i;
                }
            }
        }
    }
    int p = a[l]; int q = a[r];
    if((p+q) % 2 != 0){
        cout << "TIDAK SESUAI" << endl;
    }
    int target = (p+q)/2;
    if( p > q){
        cout << p - (p+q)/2 << " " << l+1 << " " << r +1<< endl;
    }
    else{
        cout << q - (p+q)/2 << " " << r + 1 << " " <<  l + 1 << endl;
    }
    

    return 0;
}
