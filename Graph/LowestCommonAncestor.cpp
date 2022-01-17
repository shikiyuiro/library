#include "../DataStructure/SparseTable.cpp"

class LowestCommonAncestor{
public:
    explicit LowestCommonAncestor() = default;
    
    LowestCommonAncestor(vector<vector<long>> &tree, long root) : tree(tree){
        ETpos.resize(tree.size(), -1);
        dfs(root, 0);
        st = SparseTable<long, op, e> (EularTour);
    }
    
    long query(long U, long V){
        if(ETpos[U] > ETpos[V]) swap(U, V);
        return st.query(ETpos[U], ETpos[V] + 1) % tree.size();
    }
    
private:
    vector<vector<long>> tree;
    vector<long> EularTour;
    vector<long> ETpos;
    long ETsize = 0;
    SparseTable<long, op, e> st;
    
    long op(long a, long b) { return min(a, b);}
    long e() { return LONG_MAX;}
    void dfs(long vis, long depth){
        EularTour.push_back(depth * tree.size() + vis);
        ETpos[vis] = ETsize++;
        for(auto e : tree[vis]) if(ETpos[e] == -1) {dfs(e, depth + 1); EularTour.push_back(depth * tree.size() + vis); ETsize++;}
    }
};
/**
 * @brief 最小共通祖先
 * @docs docs/Graph/LowestCommonAncestor.md
 */
