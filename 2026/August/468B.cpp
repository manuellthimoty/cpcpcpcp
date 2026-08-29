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


#include <bits/stdc++.h>
using namespace std;

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
};



void solve(){
    int n,a,b; cin >> n >> a >> b;
    set<int> st;
    for(int i = 0 ; i < n ; i++){
        int num ; cin >> num; st.insert(num);
    }    
    DisjointSets dsu(n);
    for(auto x : st){
        int complement1 = a -x;
        int complement2 = b-x;

        auto it1 = st.find(complement1);
        if(it1 != st.end()){
            dsu.unite(x,a-x);
        }
        auto it2 = st.find(complement2);
        if(it2 != st.end()){
            dsu.unite(x,b-x);
        }
    }
    for(auto p : dsu.getSizes()){
        if(p % 2 != 0){
            cout << "NO" << endl;
        }
    }
    
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
