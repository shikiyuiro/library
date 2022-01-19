#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../template/template.cpp"

#include "../../Utility/modint.cpp"

#include "../../DataStructure/SegmentTree.cpp"

#include "../../Graph/Heavy_Light_Decomposition.cpp"

using mint = modint<998244353>;

pair<mint,mint> op(pair<mint,mint> a, pair<mint,mint> b){
    return {b.first * a.first, b.first * a.second + b.second};
}
pair<mint,mint> e(){
    return {1, 0};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long N, Q; cin >> N >> Q;
    vector<pair<mint,mint>> A(N);
    for(long i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    vector<vector<long>> tree(N);
    for(long i = 0; i < N - 1; i++){
        long u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    Heavy_Light_Decomposition HLD(tree);
    auto tbl = HLD.get_table();
    vector<pair<mint,mint>> tbl_w(tbl.size());
    for(long i = 0; i < tbl.size(); i++) tbl_w[i] = A[tbl[i]];
    SegmentTree<pair<mint,mint>, op, e> seg(tbl_w);
    reverse(tbl_w.begin(), tbl_w.end());
    SegmentTree<pair<mint,mint>, op, e> ges(tbl_w);
    while(Q--){
        long q, a, b, c; cin >> q >> a >> b >> c;
        if(q == 0){
            seg.set(HLD.get_pos(a), {b, c});
            ges.set(tree.size() - HLD.get_pos(a) - 1, {b, c});
        }else{
            pair<mint,mint> res = {1, 0};
            auto v = HLD.path_decomp(a, b);
            for(auto [x, y] : v){
                if(x < y) res = op(res, seg.fold(x, y+1));
                else res = op(res, ges.fold(tree.size() - x - 1, tree.size() - y));
            }
            cout << res.first * c + res.second << '\n';
        }
    }
}
