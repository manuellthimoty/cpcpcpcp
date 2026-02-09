#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lifeguards.in","r",stdin);
    int n ; cin >> n;
    vector<pair<int,int>> shift;
    for(int i = 0 ; i < n ; i++){
        int a,b ; cin >> a >> b;
        shift.push_back(make_pair(a,b));
    }
    sort(shift.begin(),shift.end());
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        vector<pair<int,int>> Intervals;
        int curAns = 0;
        for(int j = 0 ; j < n ; j++){
            if(j == i) continue;
            if(Intervals.empty()) Intervals.push_back(make_pair(shift[j].first,shift[j].second));
            if(shift[j].first <= Intervals.back().second){
                int left = Intervals.back().first;
                int right = shift[j].second;
                Intervals.pop_back();
                Intervals.push_back(make_pair(left,right));
            }
            else{
                Intervals.push_back(make_pair(shift[j].first,shift[j].second));
            }
        }
        for(auto x : Intervals){
            curAns += abs(x.second - x.first);
        }
        ans = max(ans,curAns);

    }
    freopen("lifeguards.out","w",stdout);

    cout << ans << endl;

    return 0;
}