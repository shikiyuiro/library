class OffLCA{
public:
    OffLCA(vector<vector<long>> &tree, long root, vector<tuple<long,long,long>> &query){
        vector<vector<pair<long,long*>>> fellow(tree.size());
        for(auto& [f, s, t] : query){
            fellow[f].push_back({s, &t});
            fellow[s].push_back({f, &t});
        }
        vector<bool> visited(tree.size(), false);
        UnionFind uni(tree.size());
        auto dfs = [&](auto &&self, long vis, long prev) -> void {
            visited[vis] = true;
            for(auto e : tree[vis]) {
                if(e == prev) continue;
                self(self, e, vis);
                uni.unite(vis, e);
                uni.Size[vis] = uni.Size[uni.find(vis)];
                uni.Root[e] = vis;
                uni.Root[vis] = vis;
            }
            for(auto [e, f] : fellow[vis]) if(visited[e]) *f = uni.find(e);
        };
        dfs(dfs, root, -1);
    }
private:
    struct UnionFind{
        vector<long> Root;
        vector<long> Size;
        UnionFind(long size){ Root.resize(size); iota(Root.begin(), Root.end(), 0); Size.resize(size, 1);}
        long find(long x){ return (Root[x] == x) ? x: Root[x] = find(Root[x]); }
        void unite(long x, long y){
            if(find(x) == find(y)) return;
            if(Size[find(x)] < Size[find(y)]) swap(x, y);
            Size[find(x)] += Size[find(y)];
            Root[find(y)] = find(x);
        }
        bool same(long x, long y){ return find(x) == find(y);}
        long size(long x){ return Size[find(x)];}
    };
};
/**
 * @brief オフライン最小共通祖先
 * @docs docs/Graph/LowestCommonAncestor_Offline.md
 */
