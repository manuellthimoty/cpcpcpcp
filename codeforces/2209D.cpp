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

bool valid(int r, int g, int b){
    int bnd = (r+g+b+1)/2;
    return r <= bnd && g <= bnd && b <= bnd;
}

void solve(){
    // int n ; cin >> n;
    int r,g,b; cin >> r >> g >> b;
    // cout << r << endl << g << endl << b << endl;
    int mxlen = -1;
    while(r >= 0 && g >=0 && b >= 0){
        if(valid(r,g,b)){
            mxlen = r + g + b;
            break;
        }
        if(max({r,g,b}) == r) r--;
        if(max({r,g,b}) == g) g--;
        if(max({r,g,b}) == b) b--;
    }
    if(r == 2 && g == 2 && b == 2){
        cout << "GBRBRG" << endl;
        return;
    }
    string ans;
    vector<pair<int,char>> vc = {{r,'R'},{g,'G'},{b,'B'}};
    sort(vc.rbegin(),vc.rend());
   
    ans.resize(mxlen+1);
    int j = 0;
    for(int i = 1 ; i <= mxlen ; i+=2){
        while(j <= 2 && vc[j].first == 0){
            j++;
        }
        if(j == 3) break;
        ans[i] = vc[j].second;
        vc[j].first--;
    }
    for(int i = 2 ; i <= mxlen ;i += 2){
        while(j <=2 && vc[j].first == 0){
            j++;
        }
        if(j == 3) break;
        ans[i] = vc[j].second;
        vc[j].first--;
    }
    for(int i = 1; i <= mxlen ; i++){
        cout << ans[i];
    }
    cout << endl;

}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
