#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include<bits/stdc++.h>
using namespace std;

class Union_find{
public:
    vector<long> par;
    Union_find(long size){ par.resize(size); for(long i = 0; i < size; i++) par[i] = i; }
    long root(long x){ return (par[x] == x) ? x: par[x] = root(par[x]); }
    void unite(long x, long y){ par[root(x)] = root(y); }
    bool same(long x, long y){ return root(x) == root(y); }
};

int main(){
    long N, Q; cin >> N >> Q;
    Union_find uf(N);
    long t, u, v;
    while(Q--){
        cin >> t >> u >> v;
        if(t == 0) uf.unite(u, v);
        if(t == 1) cout << (uf.same(u, v) ? 1 : 0) << endl;
    }
}
