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

const int maxN = 2e5 + 5;
const int LOG = 19;

int st_max[maxN][LOG];
int st_min[maxN][LOG];
int lg2[maxN];


struct Segment
{
    int t_awal;
    int t_akhir;
    int y_awal;
    int y_akhir;
};

void build(vector<Segment>& segs){
    int n = segs.size();
    lg2[1] = 0;
    for(int i = 2; i <= n ; i++){
        lg2[i] = lg2[i/2] + 1;
    }

    for(int i = 0 ; i < n ; i++){
        st_max[i][0] = max(segs[i].y_awal,segs[i].y_akhir);
        st_min[i][0] = min(segs[i].y_awal,segs[i].y_akhir);
    }
    for(int j=1 ; j < LOG ; j++){
        for(int i = 0 ; i + (1 << j ) <= n;i++){
            st_max[i][j] = max(st_max[i][j-1],st_max[i+(1 << (j-1))][j-1]);
            st_min[i][j] = min(st_min[i][j-1],st_min[i+(1 << (j-1))][j-1]);

        }
    }
}

int queryMx(int L,int R){
    int j = lg2[R-L+1];
    return max(st_max[L][j],st_max[R-(1 << j) +1][j]);
}

int queryMn(int L,int R){
    int j = lg2[R-L+1];
    return min(st_min[L][j],st_min[R-(1 << j) +1][j]);
}



double compute(int t1, int y1, int t2, int y2, int tj){
    if(y1 == y2){
        return double(t1);
    }
    double ans = (double) t1 + (double) (tj - y1)/(y2-y1);
    return ans;
}

void solve(){
    
    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 0 ; i <= n ; i++) cin >> a[i];
    vector<Segment> seg(n);
    for(int i = 0 ; i < n ; i++){
        seg[i].t_awal = i;
        seg[i].t_akhir = i+1;
        seg[i].y_awal = a[i];
        seg[i].y_akhir = a[i+1];
    }
    int q; cin >> q;
    build(seg); 
    while(q--){
        int s,t; cin >> s >> t;
        if(s == n){
            if(a[n] == t) cout << fixed << setprecision(9) << (double) n << '\n';
            else cout << -1 << '\n';
            continue;
        }
        int low = 0;
        int high = n-1;
        int start_segment = (int) s;
        // while(low <= high){
        //     int mid = low + (high-low)/2;
        //     if(seg[mid].t_awal >= s){
        //         start_segment = s;
        //         high = mid-1;
        //     }
        //     else{
        //         low = mid+1;
        //     }
        // }
        int minY  = min(seg[start_segment].y_awal,seg[start_segment].y_akhir);
        int maxY  = max(seg[start_segment].y_awal,seg[start_segment].y_akhir);
        if(minY <= t && t <= maxY){
            //
            int t1 = seg[start_segment].t_awal;
            int y1 = seg[start_segment].y_awal;
            int t2 = seg[start_segment].t_akhir;
            int y2 = seg[start_segment].y_akhir;
            double ans = compute(t1,y1,t2,y2,t);
            cout << fixed << setprecision(9) <<  (double) ans << '\n';
            continue;
        }

        low = start_segment;
        high = n-1;

        int start_segment2 = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            int mnFreq = queryMn(start_segment,mid);
            int mxFreq = queryMx(start_segment,mid);
            if(mnFreq <= t && t <= mxFreq){
                high = mid-1;
                start_segment2 = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(start_segment2 == -1){
            cout << -1 << '\n';
            continue;
        }
        int t1 = seg[start_segment2].t_awal;
        int y1 = seg[start_segment2].y_awal;
        int t2 = seg[start_segment2].t_akhir;
        int y2 = seg[start_segment2].y_akhir;
        double ans = compute(t1,y1,t2,y2,t);
        cout << fixed << setprecision(9) <<  ans << '\n';




    }
}
int main() {
    GK();
    solve();

    return 0;
}
