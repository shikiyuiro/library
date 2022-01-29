#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../template/template.cpp"

#include "../../Graph/LowestCommonAncestor_Offline.cpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long N, Q; cin >> N >> Q;
    vector<vector<long>> tree(N);
    for(long i = 1; i < N; i++){
        long p; cin >> p;
        tree[p].push_back(i);
    }
    vector<tuple<long,long,long>> query;
    while(Q--){
        long u, v; cin >> u >> v;
        query.push_back({u, v, 0});
    }
    OffLCA olca(tree, 0, query);
    for(auto [f, s, t] : query) cout << t << '\n';
}
