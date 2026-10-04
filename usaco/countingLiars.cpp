#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n;
    int INF = 1e9+1;
    vector<int> aG;
    vector<int> aL;
    for(int i = 0 ; i < n ; i++){
        char s; cin >> s;
        int k ; cin >> k;
        if(s == 'G') aG.push_back(k);
        else aL.push_back(k);
    }
    sort(aG.begin(),aG.end());
    sort(aL.begin(),aL.end());
    aL.push_back(INF);
    reverse(aG.begin(),aG.end());
    aG.push_back(-1*INF);
    int nG = aG.size();
    int nL = aL.size();
    int ans = INF;
    for(int i = 0 ; i < nG ; i++){
        for(int j = 0 ; j < nL ; j++){
            if(aG[i] <= aL[j]){
                ans = min(ans,i+j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}