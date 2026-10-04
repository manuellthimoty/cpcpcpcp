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



vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) 
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i]) 
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1) 
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}
vector<int> minSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    
    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) 
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] >= nums[i]) 
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) 
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

bool check(vector<int>& mx, vector<int>& mn,int  k){
    for(int i = 0 ; i < (int)mx.size() ; i++){
        if(abs(mx[i] - mn[i]) <= k){
            return true;
        }
    }
    return false;
}
void solve(){
    int n ; cin >> n;
    int k ; cin >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    ll low = 1;
    ll high = n;
    int ans = 0;
    deque<int> max_dq;
    deque<int> min_dq;
    int L = 0;
    
    for (int R = 0; R < n; R++) {
        while (!max_dq.empty() && a[max_dq.back()] <= a[R])  max_dq.pop_back();
        max_dq.push_back(R);
        while (!min_dq.empty() && a[min_dq.back()] >= a[R]) min_dq.pop_back();
        min_dq.push_back(R);
        while (!max_dq.empty() && !min_dq.empty() && a[max_dq.front()] - a[min_dq.front()] > k) {
            if (max_dq.front() == L) max_dq.pop_front();
            if (min_dq.front() == L) min_dq.pop_front();
            L++;
        }
        
        ans = max(ans, R - L + 1);
    }
    
    cout << ans << endl;
    // while(low <= high){
    //     int mid = low + (high - low)/2;
    //     // cout << "current mid : " << mid << endl;

    //     vector<int> mx = maxSlidingWindow(a,mid);
    //     vector<int> mn = minSlidingWindow(a,mid);
    //     // for(auto m : mx) cout << m << " ";
    //     // cout << endl;
    //     // for(auto m : mn) cout << m << " ";
    //     // cout << endl;
    //     if(check(mx,mn,k)){
    //         // cout << "COCOK " << mid << endl;
    //         ans = max(ans,mid);
    //         low = mid+1;
    //     }
    //     else high = mid-1;
        
    // }
    // cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
