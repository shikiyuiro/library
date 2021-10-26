#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../template/template.cpp"

#include "../../DataStructure/UnionFind.cpp"

int main(){
    long N, Q; cin >> N >> Q;
    Union_find uf(N);
    long t, u, v;
    while(Q--){
        cin >> t >> u >> v;
        if(t == 0) uf.unite(u, v);
        if(t == 1) cout << (uf.same(u, v) ? 1 : 0) << endl;
    }
}
