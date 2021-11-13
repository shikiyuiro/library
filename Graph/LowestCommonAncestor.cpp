#include "../DataStructure/SparseTable.cpp"

class LowestCommonAncestor{
private:
    long N;
    vector<bool> visited;
    vector<vector<long> > Tree;
    vector<vector<long> > STtable;
    vector<long> STcf;
    
    void make_EularTour(long vis){
        EularTour.push_back(depth[vis] * N + vis);
        visited[vis] = true;
        for(auto e : Tree[vis]){
            if(visited[e]) continue;
            depth[e] = depth[vis] + 1;
            make_EularTour(e);
            EularTour.push_back(depth[vis] * N + vis);
        }
    }
    
    void make_SparseTable(){
        SparseTable<long> st(EularTour, LONG_MAX, [](long a, long b){return min(a, b);});
        STtable = st.table;
        STcf = st.cf;
    }
    
    void make_first(){
        long index = 0;
        for(auto e : EularTour){
            first_index[e % N] = min(first_index[e % N], index);
            index++;
        }
    }
public:
    vector<long> depth;
    vector<long> EularTour;
    vector<long> first_index;
    
    LowestCommonAncestor(vector<vector<long>>& tree, long root) : Tree(tree){
        N = Tree.size();
        visited.resize(N, false);
        depth.resize(N, 0);
        first_index.resize(N, INT_MAX);
        make_EularTour(root);
        make_SparseTable();
        make_first();
    }
    
    long query(long l, long r){
        long ltmp = l, rtmp = r;
        l = min(first_index[ltmp], first_index[rtmp]); r = max(first_index[ltmp], first_index[rtmp]) + 1;
        long b = STcf[r - l];
        return min(STtable[l][b], STtable[r - (1 << b)][b]) % N;
    }
};
/**
 * @brief 最小共通祖先
 * @docs docs/Graph/LowestCommonAncestor.md
 */
