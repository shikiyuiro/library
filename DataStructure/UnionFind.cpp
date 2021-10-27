class UnionFind{
private:
    vector<long> Root;
    vector<long> Size;
public:
    UnionFind(long size){ Root.resize(size); iota(Root.begin(), Root.end(), 0); Size.resize(size, 1);}
    long find(long x){ return (Root[x] == x) ? x: Root[x] = find(Root[x]); }
    void unite(long x, long y){ if(Size[find(x)] < Size[find(y)]) swap(x, y); Root[find(y)] = find(x); Size[find(x)] += Size[find(y)];}
    bool same(long x, long y){ return find(x) == find(y);}
    long size(long x){ return Size[find(x)];}
};
/**
 * @brief 素集合データ構造(Union Find)
 * @docs docs/DataStructure/UnionFind.md
 */
