#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../template/template.cpp"
#include "../DataStructure/LevelAncestor.cpp"

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<vector<int>> tree(N);
    for(int i = 1; i < N; i++){
        int p; cin >> p;
        tree[p].push_back(i);
    }
    LevelAncestor LA(tree, 0);
    while(Q--){
        int u, v; cin >> u >> v;
        if(LA.get_depth(u) > LA.get_depth(v)) swap(u, v);
        v = LA.query(v, LA.get_depth(u));
        if(u == v) cout << u << '\n';
        else{
            int pass = 0;
            int fail = LA.get_depth(u);
            while(fail - pass > 1){
                int mid = pass + (fail - pass) / 2;
                (LA.query(u, mid) == LA.query(v, mid) ? pass : fail) = mid;
            }
            cout << LA.query(u, pass) << '\n';
        }
    }
}
