class LevelAncestor{
    using i32 = int32_t;
public:
    explicit LevelAncestor() = default;
    LevelAncestor(vector<vector<i32>> &_tree, i32 root) : tree(&_tree){
        depth.resize(_tree.size());
        height.resize(_tree.size());
        jump.resize(_tree.size());
        Lpath.resize(_tree.size());
        Lpath_root.resize(_tree.size());
        jump[root].push_back(-1);
        calc_H(root, -1, 0);
        make_Lpath(root, root);
    }
    i32 query(i32 V, i32 D){
        if(depth[V] < D) return -1;
        if(depth[V] == D) return V;
        i32 jmp_idx = 32 - __builtin_clz(depth[V] - D) - 1;
        V = jump[V][jmp_idx];
        i32 R = Lpath_root[V];
        return Lpath[R][depth[Lpath[R][0]] - D];
    }
    i32 get_depth(i32 V){
        return depth[V];
    }
    i32 get_height(i32 V){
        return height[V];
    }
private:
    vector<i32> depth;
    vector<i32> height;
    vector<vector<i32>> *tree;
    vector<vector<i32>> jump;
    vector<i32> offline;
    vector<vector<i32>> Lpath;
    vector<i32> Lpath_root;
    i32 calc_H(i32 vis, i32 prv, i32 D){
        offline.push_back(vis);
        for(i32 b = 1; b <= D; b <<= 1) jump[vis].push_back(offline[D - b]);
        i32 H = 0;
        depth[vis] = D;
        for(auto nxt : tree->at(vis)){
            if(nxt == prv) continue;
            H = max(H, calc_H(nxt, vis, D+1) + 1);
        }
        height[vis] = H;
        offline.pop_back();
        return H;
    }
    void make_Lpath(i32 vis, i32 root){
        Lpath_root[vis] = root;
        i32 L_nxt = -1;
        for(auto nxt : tree->at(vis)) if(height[nxt]+1 == height[vis]) L_nxt = nxt;
        for(auto nxt : tree->at(vis)){
            if(depth[nxt] != depth[vis]+1) continue;
            if(nxt == L_nxt) make_Lpath(nxt, root);
            else make_Lpath(nxt, nxt);
        }
        Lpath[root].push_back(vis);
        if(vis == root){
            i32 ladder_size = (i32)Lpath.size();
            i32 parent = jump[vis][0];
            while(parent != -1 and ladder_size--){
                Lpath[root].push_back(parent);
                parent = jump[parent][0];
            }
        }
    }
};
/**
 * @brief Level Ancestor( 構築$\mathrm{O}(NlogN)$・クエリ$\mathrm{O}(1)$ )
 * @docs docs/DataStructure/LevelAncestor.md
 */
