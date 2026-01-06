// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t ; cin >> t ;
//     while(t--){
//         ll n ; cin >> n ; 
//         vector<ll> a(n);
//         for(ll i = 0 ; i < n ; i++){
//             cin >> a[i];
//         }
//         ll min_elmt = *min_element(a.begin(),a.end());
//         ll min_idx = 0;
//         for(ll i = 0 ; i < n ; i++){
//             if(a[i] == min_elmt){
//                 min_idx = i;
//                 break;
//             }
//         }
//         long long count = a.size()-1;
//         long long ans = 0;
//         long long p = min_idx;
//         long long left = (p-1) % a.size();
//         long long right = (p+1) % a.size();
//         long long curr_max = 0;
//         while(count--){
//             if(left == right){
//                 ans += a[left];
//                 break;
//             }
//             if(a[left]<a[right]){
//                 curr_max = max(curr_max, a[left]);
//                 ans += curr_max;
//                 left = (left -1) % a.size();
//             }
//             if(a[left]>=a[right]){
//                 curr_max = max(curr_max, a[right]);
//                 ans += curr_max;
//                 right = (right+1) % a.size();
//             }
//         }

//         cout << ans << endl;
//         // 5 3 1 1 4
//         // 1 4 3 5 1
//         //
//     }
// }
    

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        // find index of first minimum
        ll mn = *min_element(a.begin(), a.end());
        int p = 0;
        for(int i=0;i<n;i++) if(a[i]==mn){ p = i; break; }

        // linked list neighbors
        vector<int> L(n), R(n);
        for(int i=0;i<n;i++){
            L[i] = (i-1 + n) % n;
            R[i] = (i+1) % n;
        }

        ll ans = 0;
        ll curr = a[p];        // current merged value
        int curr_idx = p;
        int remaining = n;

        while(remaining > 1){
            int left = L[curr_idx];
            int right = R[curr_idx];

            // if only two elements left (left == right), merge with that one and finish
            if(left == right){
                ans += max(curr, a[left]);
                // merged into one element; done
                break;
            }

            int choose;
            if(a[left] < a[right]) choose = left;
            else choose = right;

            ans += max(curr, a[choose]);
            curr = max(curr, a[choose]);
            // 3 2 1 1 4
            //choose = right = 3

            int Lc = L[choose];
            //Lc = L[3]= 2
            //Rc = R[3] = 4

            int Rc = R[choose];
            R[Lc] = Rc;
            L[Rc] = Lc;
            remaining--;
        }

        cout << ans << '\n';
    }
    return 0;
}
