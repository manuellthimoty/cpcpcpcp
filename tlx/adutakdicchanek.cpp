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
const int mxA = 1e6;
int spf[mxA + 1];

void init() {
    for (int i = 2; i <= mxA; i++) spf[i] = i;
    for (int i = 2; i * i <= mxA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}


class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
    vector<int> getSizes(){
        return sizes;
    }
    vector<int> getParents(){ return parents;}
};

void solve(){
    init();
    int n ,k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> idx(1e6+5,-1);
    DisjointSets ds(n);
    // for(auto x : a) cout << x;
    for(int i = 0 ; i < n ; i++){
        int cur = a[i];
        while(cur > 1){
            int curPrime = spf[cur];

            if(idx[curPrime] == -1){
                idx[curPrime] = i;
            }
            else{
                ds.unite(idx[curPrime],i);
            }
            while(cur % curPrime == 0){
                cur /= curPrime;
            }
        }
    }
    vector<ll> res(n+5,1);
    for(int i = 0 ; i < n ; i++){
        int curRoot = ds.find(i); 
        res[curRoot] = (res[curRoot] * (a[i] % k)) % k;
    }
    
    for(int i = 0 ; i < n ; i++){
    int curRoot = ds.find(i);
        if(res[curRoot] == 0){ 
            cout << "YA";
            return;
        }
    }

    cout << "TIDAK";
}
int main() {
    GK();

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
