#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("triangles.in", "r", stdin);
    
    vector<pair<ll,ll>> points;
    int n ; cin >> n;
    for(int i = 0 ; i < n ; i++){
        ll xi,yi; cin >> xi >> yi;
        points.push_back(make_pair(xi,yi));
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == i) continue;
            if(points[i].second == points[j].second){
                for(int k = 0 ; k < n ; k++){
                    if(k ==  i || k == j) continue;
                    if(points[i].first == points[k].first){
                        ll dx = abs(points[i].first - points[j].first);
                        ll dy = abs(points[i].second - points[k].second);
                        ans = max(ans, dx * dy);
                    }
                }
            }
        }
    }
    freopen("triangles.out", "w", stdout);

    cout << ans << endl;
    

    return 0;
}