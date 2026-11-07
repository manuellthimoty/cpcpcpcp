#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n ; cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> anak(n+1,1);
    vector<int> deg(n+1,0);
    for(int i = 0 ; i < n -1 ; i++){
        int u,v; cin >> u >> v;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;

    for(int i = 1; i <= n ; i++){
        if(deg[i] == 1){
            pq.push({1,{i,adj[i][0]}});
        }
    }
    int cnt = 0;
    cout << 2 * (n-1) << '\n';
    while(!pq.empty()){
        int curnode = pq.top().second.first;
        int nextnode = pq.top().second.second;
        pq.pop();
        if(cnt == (n-1)) break;
        anak[nextnode] += anak[curnode];
        deg[curnode]--;
        deg[nextnode]--;

        cout << "M " << curnode << " " << nextnode << '\n';
        cout << "A " << curnode << '\n';
        if(deg[nextnode] == 1){
            int active = -1;
            for(auto neigh : adj[nextnode]){
                if(deg[neigh] > 0){
                    active = neigh;
                    break;
                }
            }
            pq.push({anak[nextnode],{nextnode,active}});
        }
        cnt++;

    }
}
