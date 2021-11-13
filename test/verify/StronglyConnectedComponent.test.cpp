#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../template/template.cpp"

#include "../../Graph/StronglyConnectedComponent.cpp"

int main(){
    long N, M; cin >> N >> M;
    vector<vector<long>> graph(N);
    while(M--){
        long a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    
    StronglyConnectedComponent scc(graph);
    auto res = scc.result;
    cout << res.size() << endl;
    for(auto e : res){
        cout << e.size() << " ";
        for(auto f : e) cout << f << " ";
        cout << endl;
    }
}
