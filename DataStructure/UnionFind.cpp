class Union_find{
public:
    vector<long> par;
    Union_find(long size){ par.resize(size); for(long i = 0; i < size; i++) par[i] = i; }
    long root(long x){ return (par[x] == x) ? x: par[x] = root(par[x]); }
    void unite(long x, long y){ par[root(x)] = root(y); }
    bool same(long x, long y){ return root(x) == root(y); }
};
/**
 * @brief 素集合データ構造(Union Find)
 * @docs docs/DataStructure/UnionFind.md
 */
