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

class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;
    int num_components;
    int mxsz;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
        num_components = size;
        mxsz = 1;
	}

	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
        if(sizes[x_root] > mxsz){
            mxsz = sizes[x_root];
        }
		parents[y_root] = x_root;
        num_components--;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
    vector<int> getSizes(){
        return sizes;
    }
    int get_num_components(){
        return num_components;
    }

    int getmx(){
        return mxsz;
    }

};

int main() {
    int n,m ; cin >> n >> m;
    DisjointSets dsu(n);
    vector<pair<int,int>> ans;
    for(int i = 0  ; i < m ; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        dsu.unite(a,b);
        int first = dsu.get_num_components();
        int second = dsu.getmx();
        ans.push_back({first,second});
    }
    for(auto xss : ans){
        cout << (int) xss.first << " " << (int) xss.second << endl;
    }

    return 0;
}
