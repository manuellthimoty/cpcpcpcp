#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("balancing.in","r",stdin);
    int n ; cin >> n;
    vector<pair<int,int>> points;
    for (int i = 0; i < n; i++)
    {
        int x,y ; cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    vector<int> x_vals,y_vals;
    for(auto p : points) {
        x_vals.push_back(p.first - 1);
        x_vals.push_back(p.first + 1);
        y_vals.push_back(p.second - 1);
        y_vals.push_back(p.second + 1);
    }

    int ans = 1e3 + 1;
    for(int a : x_vals) {
        for(int b : y_vals) {
            int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
            for(auto p : points) {
                if(p.first > a && p.second > b) pos1++;
                else if(p.first < a && p.second > b) pos2++;
                else if(p.first < a && p.second < b) pos3++;
                else if(p.first > a && p.second < b) pos4++;
            }
            int curMax = max({pos1, pos2, pos3, pos4});
            ans = min(ans, curMax);
        }
    }
    freopen("balancing.out","w",stdout);
    cout << ans << endl;

    

    return 0;
}