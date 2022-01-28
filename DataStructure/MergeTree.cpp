#include "../DataStructure/UnionFind_PartiallyPersistent.cpp"

class MergeTree{
    //UnionFindのマージ過程を表す木(のオイラーツアー)。  
    //「時刻tにおける要素uの連結成分」に対するクエリを列クエリに帰着できる。  
    //追加する辺とその時刻が先読み可能である必要がある。
public:
    MergeTree(long siz, vector<tuple<long,long,long>> merge){
        uni = PPUF(siz);
        forest.resize(siz);
        pos.resize(siz);
        for(auto [u, v, t] : merge){
            long fu = uni.find(u, t), fv = uni.find(v, t);
            if(uni.unite(fu, fv, t)){
                forest[fu].push_back(fv);
                forest[fv].push_back(fu);
            }
        }
        vector<bool> visited(siz, false);
        for(long v = 0; v < siz; v++){
            if(visited[v]) continue;
            long fv = uni.find(v, INT_MAX);
            auto dfs = [&](auto &&self, long vis, long prev) -> void {
                visited[vis] = true;
                tour.push_back(vis);
                pos[vis] = tour.size() - 1;
                for(auto e : forest[vis]) if(e != prev) self(self, e, vis);
            };
            dfs(dfs, fv, -1);
        }
    }
    vector<long> get_tour(){
        return tour;
    }
    pair<long,long> get_range(long u, long t){
        long L = pos[uni.find(u, t)];
        return {L, L + uni.size(u, t)};
    }
private:
    vector<vector<long>> forest;
    vector<long> tour;
    vector<long> pos;
    PPUF uni;
};
/**
 * @brief マージ過程を表す木
 */
