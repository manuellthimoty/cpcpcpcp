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

struct Node{
    int out[16];
};

Node tree[4 * 200005];
char op_type[200005];
int op_val[200005];


Node merge(Node left, Node right){
    Node parent;
    for(int x = 0 ; x < 16 ; x++){
        parent.out[x] = right.out[left.out[x]];
    }
    return parent;
}

void build(int node, int start, int end){
    if(start == end){
        for(int x = 0 ;x < 16 ; x++){
            if(op_type[start] == '+'){
                tree[node].out[x] = (x + op_val[start])%16;
            }
            else tree[node].out[x] = (x ^ op_val[start]);
        }
        return;
    }
    int mid = (start+end)/2;
    build(2 * node, start,mid);
    build(2 * node+1, mid+1,end);
    
    tree[node] = merge(tree[2*node],tree[2*node+1]);
}

void update(int node, int start, int end,int idx, char new_type, int new_val){
    if(start == end){
        for(int x = 0 ; x < 16 ; x++){
            if(new_type == '+'){
                tree[node].out[x] = (x + new_val)%16;
            }
            else tree[node].out[x] = (x ^ new_val);
        }
        return;
    }
    int mid = (start+end)/2;

    if (idx <= mid) update(2 * node, start, mid, idx, new_type, new_val);
    else update(2 * node + 1, mid + 1, end, idx, new_type, new_val);    

    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    GK();
    int n,q; cin >> n >> q;
    for(int i = 1 ; i <= n ; i++){
        cin >> op_type[i] >> op_val[i];
    }
    build(1,1,n);
    while(q--){
        int idx, newVal;
        char newType;
        cin >> idx >> newType >> newVal;
        update(1,1,n,idx,newType,newVal);
        cout << tree[1].out[0] << '\n';
    }
    


    return 0;
}
