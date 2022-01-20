class Heavy_Light_Decomposition{
public:
    
    Heavy_Light_Decomposition(vector<vector<long>> &tree, long root = 0) : tree(tree), root(root){
        depth.resize(tree.size(), 0);
        heavy.resize(tree.size(), -1);
        subtree_size.resize(tree.size(), 1);
        calc_depth(root, -1);
        table_index.resize(tree.size(), -1);
        terminal.resize(tree.size(), {root, -1});
        tour();
    }
    
    vector<long> get_table(){
        return table;
    }
    
    vector<pair<long,long>> path_decomp(long u, long v, bool edge_is_weighted = false){
        vector<pair<long,long>> res;
        stack<pair<long,long>> ser;
        while(terminal[u].first != terminal[v].first){
            auto [TermiU, TransU] = terminal[u];
            auto [TermiV, TransV] = terminal[v];
            if(depth[TermiU] >= depth[TermiV]){
                res.push_back({table_index[u], table_index[TermiU]});
                u = TransU;
            }else{
                ser.push({table_index[TermiV], table_index[v]});
                v = TransV;
            }
        }
        if(edge_is_weighted){
            if(u == v){
                while(not ser.empty()){
                    auto p = ser.top(); ser.pop();
                    res.push_back(p);
                }
                return res;
            }
            if(table_index[u] < table_index[v]) res.push_back({table_index[heavy[u]], table_index[v]});
            else res.push_back({table_index[u], table_index[heavy[v]]});
        }else{
            res.push_back({table_index[u], table_index[v]});
        }
        while(not ser.empty()){
            auto p = ser.top(); ser.pop();
            res.push_back(p);
        }
        return res;
    }
    
    pair<long,long> subtree_decomp(long v){
        return {table_index[v], table_index[v] + subtree_size[v] - 1};
    }
    
    vector<long> depth;
private:
    long root;
    vector<vector<long>> &tree;
    vector<long> heavy;
    vector<long> subtree_size;
    vector<long> table;
    vector<long> table_index;
    vector<pair<long,long>> terminal;
    void calc_depth(long vis, long prev){
        if(prev != -1) depth[vis] = depth[prev] + 1;
        long max_subtree_size = 0;
        for(auto nex : tree[vis]){
            if(nex == prev) continue;
            calc_depth(nex, vis);
            subtree_size[vis] += subtree_size[nex];
            if(subtree_size[nex] <= max_subtree_size) continue;
            max_subtree_size = subtree_size[nex];
            heavy[vis] = nex;
        }
    }
    void tour(){
        stack<long> Q; Q.push(root);
        while(not Q.empty()){
            long t = Q.top(); Q.pop();
            table.push_back(t);
            table_index[t] = table.size() - 1;
            for(auto nex : tree[t]){
                if(depth[nex] < depth[t]) continue;
                if(nex == heavy[t]) continue;
                Q.push(nex);
                terminal[nex] = {nex, t};
            }
            if(heavy[t] != -1){
                Q.push(heavy[t]);
                terminal[heavy[t]] = terminal[t];
            }
        }
    }
    
};
/**
 * @brief HL分解
 * @docs docs/Graph/Heavy_Light_Decomposition.md
 */
