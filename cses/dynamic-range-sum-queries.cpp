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

struct Node {
    ll val;
};
Node identity() {
    return {0};
}
Node make_node(ll x) {
    return {x};
}
Node merge(Node a, Node b) {
    return {a.val + b.val};
    // return {a.val ^ b.val};
}
struct SegTree {
    int n;
    vector<Node> tree;
    SegTree(const vector<ll>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
    void build(int node, int l, int r,
    const vector<ll>& a) {
        if (l == r) {tree[node] = make_node(a[l]);return;}
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = merge(tree[node * 2],
        tree[node * 2 + 1]);
        }
    void update(int node, int l, int r, int idx, ll x) {
        if (l == r) {
            tree[node] = make_node(x);
        return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(node * 2, l, mid, idx, x);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, x);
        }
        tree[node] = merge(tree[node * 2],
        tree[node * 2 + 1]);
        }
    Node query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return identity();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        Node a = query(node * 2, l, mid, ql, qr);
        Node b = query(node * 2 + 1, mid + 1, r, ql, qr);
        return merge(a, b);
    }
    void update(int idx, ll x) {
        update(1, 0, n - 1, idx, x);
    }
    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};


Node identity() {
    return {0};
}
Node make_node(ll x) {
    return {x};
}
Node merge(Node a, Node b) {
    return {a.val + b.val};
    // return {a.val ^ b.val};
}
struct SegTree {
    int n;
    vector<Node> tree;
    SegTree(const vector<ll>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
    void build(int node, int l, int r,
    const vector<ll>& a) {
        if (l == r) {tree[node] = make_node(a[l]);return;}
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = merge(tree[node * 2],
        tree[node * 2 + 1]);
        }
    void update(int node, int l, int r, int idx, ll x) {
        if (l == r) {
            tree[node] = make_node(x);
        return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(node * 2, l, mid, idx, x);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, x);
        }
        tree[node] = merge(tree[node * 2],
        tree[node * 2 + 1]);
        }
    Node query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return identity();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        Node a = query(node * 2, l, mid, ql, qr);
        Node b = query(node * 2 + 1, mid + 1, r, ql, qr);
        return merge(a, b);
    }
    void update(int idx, ll x) {
        update(1, 0, n - 1, idx, x);
    }
    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n ; cin >> n;
    vector<int> arr(n), p(n);
    vector<ll> pos(n,1);
    SegTree seg(pos);
    for(int i = 0; i < n ; i++) cin >> arr[i];
    for(int i = 0 ;i < n ; i++) cin >> p[i];
    for(int i = 0; i < n ; i++){
        int cur = p[i];
        // cur--;
        int low = 0;
        int high = n-1;
        int res = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int curpref = seg.query(0,mid).val;
            if(curpref == cur){
                res = mid;
                high = mid-1;
            }
            else if(curpref < cur){
                low = mid+1;
            }
            else high = mid-1;
        }
        if(res != -1) {
            cout << arr[res] << " ";
            seg.update(res,0);
        }
        
    }
    // cout << seg.query(0,2).val << endl;
}