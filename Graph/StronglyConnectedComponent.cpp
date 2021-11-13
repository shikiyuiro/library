class StronglyConnectedComponent{
private:
    long Gsize;
    vector<bool> visited;
    vector<vector<long>> forward;
    vector<vector<long>> backward;
    stack<long> bfs_seed;
    
    void dfs(){
        fill(visited.begin(), visited.end(), false);
        for(long i = 0; i < Gsize; i++){
            dfs_rec(i);
        }
    }
    
    void dfs_rec(long i){
        if(visited[i]) return;
        visited[i] = true;
        for(auto e : forward[i]){
            dfs_rec(e);
        }
        bfs_seed.push(i);
    }
    
    void bfs(){
        fill(visited.begin(), visited.end(), false);
        queue<long> bfs;
        while(not bfs_seed.empty()){
            long t = bfs_seed.top(); bfs_seed.pop();
            if(visited[t]) continue;
            bfs.push(t);
            vector<long> result_seed;
            while(not bfs.empty()){
                long f = bfs.front(); bfs.pop();
                if(visited[f]) continue;
                visited[f] = true;
                for(auto e : backward[f]){
                    bfs.push(e);
                }
                result_seed.push_back(f);
            }
            result.push_back(result_seed);
        }
    }
    
public:
    vector<vector<long>> result;
    
    StronglyConnectedComponent(vector<vector<long>> &graph) : forward(graph){
        Gsize = graph.size();
        visited.resize(Gsize);
        backward.resize(Gsize);
        for(long e = 0; e < Gsize; e++) for(auto f : graph[e]) backward[f].push_back(e);
        dfs();
        bfs();
    }
};
