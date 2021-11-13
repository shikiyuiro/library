#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../template/template.cpp"

#include "../../Graph/LowestCommonAncestor.cpp"

int main(){
    long N, Q; cin >> N >> Q;
    vector<vector<long>> tree(N);
    for(long i = 1; i <= N - 1; i++){
        long p; cin >> p;
        tree[i].push_back(p);
        tree[p].push_back(i);
    }
    
    LowestCommonAncestor lca(tree, 0);
    while(Q--){
        long u, v; cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}
